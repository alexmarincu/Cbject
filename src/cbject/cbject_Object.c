#include "cbject_Object.h"
#include "cbject_internal.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define cbject_Class (cbject_Object, NULL)

#if (cbject_config_useStaticPool == true)
cbject_noPool;

cbject_Object * cbject_Object_allocHelper(
    cbject_Object * const self,
    cbject_ObjectClass * const klass,
#if (cbject_config_useStaticPool == true) || (cbject_config_useHeap == true)
    cbject_Object_Source const source
#endif
) {
    self->klass = klass;
    self->referenceCount = 1;
#if (cbject_config_useStaticPool == true) || (cbject_config_useHeap == true)
    self->source = source;
#endif
    return self;
}

cbject_Object * cbject_ObjectClass_acquire(cbject_ObjectClass * const self) {
    return cbject_invokeClassMethod(acquire, self);
}

static cbject_Object * acquire(cbject_ObjectClass * const self) {
    cbject_Object * object = NULL;
    if ((void *)self->poolFirstFreeObject < ((void *)self->pool + (self->instanceSize * self->poolSize))) {
        object = self->poolFirstFreeObject;
        memset(object, 0, self->instanceSize);
        cbject_Object_allocHelper(object, self, cbject_Object_Source_staticPool);
        object->poolUsageStatus = cbject_Object_PoolUsageStatus_inUse;
        do {
            self->poolFirstFreeObject = (void *)self->poolFirstFreeObject + self->instanceSize;
        } while ((self->poolFirstFreeObject->poolUsageStatus != cbject_Object_PoolUsageStatus_free) //
                 && ((void *)self->poolFirstFreeObject < ((void *)self->pool + (self->instanceSize * self->poolSize)))
        );
    }
    assert(object);
    return object;
}

static void dispose(cbject_Object * const self) {
    self->poolUsageStatus = cbject_Object_PoolUsageStatus_free;
    if (self < self->klass->poolFirstFreeObject) {
        self->klass->poolFirstFreeObject = self;
    }
}
#endif // (cbject_config_useStaticPool == true)

#if (cbject_config_useHeap == true)
cbject_Object * cbject_ObjectClass_alloc(cbject_ObjectClass * const self) {
    return cbject_invokeClassMethod(alloc, self);
}

static cbject_Object * alloc(cbject_ObjectClass * const self) {
    cbject_Object * object = (cbject_Object *)calloc(1, self->instanceSize);
    assert(object);
    cbject_Object_allocHelper(object, self, cbject_Object_Source_heap);
    return object;
}

static void dealloc(cbject_Object * const self) {
    free(self);
}
#endif // (cbject_config_useHeap == true)

cbject_Object * cbject_Object_retain(cbject_Object * const self) {
    self->referenceCount++;
    return self;
}

void * cbject_Object_release(cbject_Object * const self) {
    self->referenceCount--;
    if (self->referenceCount == 0) {
        cbject_invokeMethod(terminate, self);
#if (cbject_config_useStaticPool == true) || (cbject_config_useHeap == true)
        switch (self->source) {
#if (cbject_config_useHeap == true)
            case cbject_Object_Source_heap:
                dealloc(self);
                break;
#endif
#if (cbject_config_useStaticPool == true)
            case cbject_Object_Source_staticPool:
                dispose(self);
                break;
#endif
            case cbject_Object_Source_stack:
            default:
                break;
        }
#endif
    }
    return NULL;
}

cbject_Object * cbject_Object_init(cbject_Object * const self) {
    return self;
}

cbject_Object * cbject_Object_copy(cbject_Object const * const self, cbject_Object * const object) {
    return cbject_invokeMethod(copy, self, object);
}

static cbject_Object * copy(cbject_Object const * const self, cbject_Object * const object) {
    memcpy(object, self, cbject_Object_instanceSize(self));
    return object;
}

bool cbject_Object_equals(cbject_Object const * const self, cbject_Object const * const object) {
    return cbject_invokeMethod(equals, self, object);
}

static bool equals(cbject_Object const * const self, cbject_Object const * const object) {
    return self == object;
}

uint64_t cbject_Object_hashCode(cbject_Object const * const self) {
    return cbject_invokeMethod(hashCode, self);
}

static uint64_t hashCode(cbject_Object const * const self) {
    return (uint64_t)self;
}

static cbject_Object * terminate(cbject_Object * const self) {
    (void)(self);
    return NULL;
}

bool cbject_Object_isOfClass(cbject_Object const * const self, cbject_ObjectClass const * const klass) {
    bool isOfType = false;
    cbject_ObjectClass const * _klass = self->klass;
    while (_klass != NULL) {
        if (_klass == klass) {
            isOfType = true;
            _klass = NULL;
        } else {
            _klass = _klass->superClass;
        }
    }
    return isOfType;
}

cbject_ObjectClass * cbject_ObjectClass_instance(void) {
    static cbject_ObjectClass self;
    cbject_doOnce {
        self.name = "cbject_Object";
        self.instanceSize = sizeof(cbject_Object);
        self.superClass = NULL;
#if (cbject_config_useStaticPool == true)
        self.pool = cbject_Object_pool;
        self.poolSize = cbject_Object_poolSize;
        self.poolFirstFreeObject = cbject_Object_pool;
        self.acquire = acquire;
#endif
#if (cbject_config_useHeap == true)
        self.alloc = alloc;
#endif
        self.copy = copy;
        self.equals = equals;
        self.hashCode = hashCode;
        self.terminate = terminate;
    }
    return &self;
}

#undef cbject_Class