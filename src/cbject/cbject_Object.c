#include "cbject_Object.h"
#include "cbject_utils.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define cbject_Class (cbject_Object, NULL)

#if cbject_config_useStaticPool == true
cbject_utils_allocPool(0);

cbject_Object * cbject_Object_acquire(cbject_ObjectClass * const objectClass) {
    return cbject_utils_invokeClassMethod(acquire, objectClass);
}

static cbject_Object * acquire(cbject_ObjectClass * const objectClass) {
    cbject_Object * object = NULL;
    if (objectClass->firstFreeObject != &objectClass->pool[objectClass->poolSize]) {
        object = objectClass->firstFreeObject;
        memset(object, 0, objectClass->instanceSize);
        object->objectClass = objectClass;
        object->usageStatus = cbject_Object_UsageStatus_inUse;
        do {
            objectClass->firstFreeObject = objectClass->firstFreeObject + objectClass->instanceSize;
        } while ((objectClass->firstFreeObject->usageStatus != cbject_Object_UsageStatus_free) //
                 && (objectClass->firstFreeObject != &objectClass->pool[objectClass->poolSize])
        );
    }
    return object;
}

void * cbject_Object_release(cbject_Object * const object) {
    return cbject_utils_invokeMethod(release, object);
}

static void * release(cbject_Object * const object) {
    cbject_Object_terminate((cbject_Object *)object);
    object->usageStatus = cbject_Object_UsageStatus_free;
    if (object < object->objectClass->firstFreeObject) {
        object->objectClass->firstFreeObject = object;
    }
    return NULL;
}
#endif

#if cbject_config_useHeap == true
cbject_Object * cbject_Object_alloc(cbject_ObjectClass * const objectClass) {
    return cbject_utils_invokeClassMethod(alloc, objectClass);
}

static cbject_Object * alloc(cbject_ObjectClass * const objectClass) {
    cbject_Object * object = (cbject_Object *)calloc(1, objectClass->instanceSize);
    assert(object);
    object->objectClass = objectClass;
    return object;
}

void * cbject_Object_dealloc(cbject_Object * const object) {
    return cbject_utils_invokeMethod(dealloc, object);
}

static void * dealloc(cbject_Object * const object) {
    cbject_Object_terminate((cbject_Object *)object);
    free(object);
    return NULL;
}
#endif

cbject_Object * cbject_Object_init(cbject_Object * const object) {
    return object;
}

cbject_Object * cbject_Object_setClass(cbject_Object * const object, cbject_ObjectClass * const objectClass) {
    object->objectClass = objectClass;
    return object;
}

cbject_Object * cbject_Object_copy(cbject_Object const * const object, cbject_Object * const copyObject) {
    return cbject_utils_invokeMethod(copy, object, copyObject);
}

static cbject_Object * copy(cbject_Object const * const object, cbject_Object * const copyObject) {
    memcpy(copyObject, object, object->objectClass->instanceSize);
    return copyObject;
}

bool cbject_Object_equals(cbject_Object const * const object, cbject_Object const * const otherObject) {
    return cbject_utils_invokeMethod(equals, object, otherObject);
}

static bool equals(cbject_Object const * const object, cbject_Object const * const otherObject) {
    return object == otherObject;
}

uint64_t cbject_Object_hashCode(cbject_Object const * const object) {
    return cbject_utils_invokeMethod(hashCode, object);
}

static uint64_t hashCode(cbject_Object const * const object) {
    return (uint64_t)object;
}

cbject_Object * cbject_Object_terminate(cbject_Object * const object) {
    return cbject_utils_invokeMethod(terminate, object);
}

static cbject_Object * terminate(cbject_Object * const object) {
    (void)(object);
    return NULL;
}

bool cbject_Object_isOfClass(cbject_Object const * const object, cbject_ObjectClass const * const objectClass) {
    bool isOfClass = false;
    cbject_ObjectClass const * _objectClass = object->objectClass;
    while (_objectClass != NULL) {
        if (_objectClass == objectClass) {
            isOfClass = true;
            _objectClass = NULL;
        } else {
            _objectClass = _objectClass->superClass;
        }
    }
    return isOfClass;
}

cbject_ObjectClass * cbject_ObjectClass_instance(void) {
    static cbject_ObjectClass klass;
    cbject_utils_doOnce {
        klass.name = "cbject_Object";
        klass.instanceSize = sizeof(cbject_Object);
        klass.superClass = NULL;
#if cbject_config_useStaticPool == true
        klass.pool = cbject_Object_pool;
        klass.poolSize = cbject_utils_Array_length(cbject_Object_pool);
        klass.firstFreeObject = cbject_Object_pool;
        klass.acquire = acquire;
        klass.release = release;
#endif
#if cbject_config_useHeap == true
        klass.alloc = alloc;
        klass.dealloc = dealloc;
#endif
        klass.copy = copy;
        klass.equals = equals;
        klass.hashCode = hashCode;
        klass.terminate = terminate;
    }
    return &klass;
}

#undef cbject_Class