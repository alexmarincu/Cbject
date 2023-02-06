#include "cbject_Object.h"
#include <stdlib.h>
#include <string.h>

#define cbject_Class (cbject_Object, NULL)

cbject_Object * cbject_Object_alloc(cbject_ObjectClass const * const objectClass) {
    return cbject_utils_invokeClassMethod(alloc, objectClass);
}

static cbject_Object * alloc(cbject_ObjectClass const * const objectClass) {
    cbject_Object * object = (cbject_Object *)calloc(1, objectClass->instanceSize);
    assert(object);
    object->objectClass = objectClass;
    return object;
}

cbject_Object * cbject_Object_init(cbject_Object * const object) {
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

void * cbject_Object_dealloc(cbject_Object * const object) {
    return cbject_utils_invokeMethod(dealloc, object);
}

static void * dealloc(cbject_Object * const object) {
    cbject_Object_terminate((cbject_Object *)object);
    free(object);
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

cbject_ObjectClass const * cbject_ObjectClass_instance(void) {
    static cbject_ObjectClass klass;
    cbject_utils_doOnce {
        klass.name = "cbject_Object";
        klass.instanceSize = sizeof(cbject_Object);
        klass.superClass = NULL;
        klass.alloc = alloc;
        klass.copy = copy;
        klass.equals = equals;
        klass.hashCode = hashCode;
        klass.terminate = terminate;
        klass.dealloc = dealloc;
    }
    return &klass;
}

#undef cbject_Class