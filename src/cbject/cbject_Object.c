#include "cbject_Object.h"
#include "cbject_utils.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define cbject_Class (cbject_Object, NULL)

#if (cbject_config_useStaticPool == true)
cbject_utils_nullPool;

cbject_Object * cbject_ObjectClass_acquire(cbject_ObjectClass * const self) {
    return cbject_utils_invokeClassMethod(acquire, self);
}

static cbject_Object * acquire(cbject_ObjectClass * const self) {
    cbject_Object * object = NULL;
    if ((void *)self->poolFirstFreeObject < ((void *)self->pool + (self->instanceSize * self->poolSize))) {
        object = self->poolFirstFreeObject;
        memset(object, 0, self->instanceSize);
        object->objectClass = self;
        object->referenceCount = 1;
        object->source = cbject_Object_Source_staticPool;
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
    if (self < self->objectClass->poolFirstFreeObject) {
        self->objectClass->poolFirstFreeObject = self;
    }
}
#endif // (cbject_config_useStaticPool == true)

#if (cbject_config_useHeap == true)
cbject_Object * cbject_ObjectClass_alloc(cbject_ObjectClass * const self) {
    return cbject_utils_invokeClassMethod(alloc, self);
}

static cbject_Object * alloc(cbject_ObjectClass * const self) {
    cbject_Object * object = (cbject_Object *)calloc(1, self->instanceSize);
    assert(object);
    object->objectClass = self;
    object->referenceCount = 1;
    object->source = cbject_Object_Source_heap;
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
        cbject_utils_invokeMethod(terminate, self);
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

cbject_Object * cbject_Object_allocHelper(cbject_Object * const self, cbject_ObjectClass * const objectClass) {
    self->objectClass = objectClass;
    self->referenceCount = 1;
#if (cbject_config_useStaticPool == true) || (cbject_config_useHeap == true)
    self->source = cbject_Object_Source_stack;
#endif
    return self;
}

cbject_Object * cbject_Object_copy(cbject_Object const * const self, cbject_Object * const object) {
    return cbject_utils_invokeMethod(copy, self, object);
}

static cbject_Object * copy(cbject_Object const * const self, cbject_Object * const object) {
    memcpy(object, self, cbject_Object_instanceSize(self));
    return object;
}

bool cbject_Object_equals(cbject_Object const * const self, cbject_Object const * const object) {
    return cbject_utils_invokeMethod(equals, self, object);
}

static bool equals(cbject_Object const * const self, cbject_Object const * const object) {
    return self == object;
}

uint64_t cbject_Object_hashCode(cbject_Object const * const self) {
    return cbject_utils_invokeMethod(hashCode, self);
}

static uint64_t hashCode(cbject_Object const * const self) {
    return (uint64_t)self;
}

static cbject_Object * terminate(cbject_Object * const self) {
    (void)(self);
    return NULL;
}

bool cbject_Object_isOfType(cbject_Object const * const self, cbject_ObjectClass const * const objectClass) {
    bool isOfType = false;
    cbject_ObjectClass const * _objectClass = self->objectClass;
    while (_objectClass != NULL) {
        if (_objectClass == objectClass) {
            isOfType = true;
            _objectClass = NULL;
        } else {
            _objectClass = _objectClass->superClass;
        }
    }
    return isOfType;
}

cbject_ObjectClass * cbject_ObjectClass_instance(void) {
    static cbject_ObjectClass self;
    cbject_utils_doOnce {
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