#include "cbject_Object.h"
#include <stdlib.h>
#include <string.h>
static cbject_Object * teardown(cbject_Object * object);
static cbject_Object * copy(cbject_Object const * const object, cbject_Object * const copyObject);
static bool equals(cbject_Object const * const object, cbject_Object const * const otherObject);
static uint64_t hashCode(cbject_Object const * const object);
cbject_ObjectClass const * cbject_ObjectClass_getInstance(void) {
    static cbject_ObjectClass objectClass = {
        .name = "Object",
        .objectSize = sizeof(cbject_Object),
        .superClass = NULL,
        .teardown = teardown,
        .copy = copy,
        .equals = equals,
        .hashCode = hashCode
    };
    return &objectClass;
}
cbject_Object * cbject_ObjectClass_alloc(cbject_ObjectClass const * const objectClass) {
    cbject_Object * object = (cbject_Object *)calloc(1, objectClass->objectSize);
    assert(object);
    object->objectClass = objectClass;
    return object;
}
cbject_Object * cbject_Object_dealloc(cbject_Object * const object) {
    cbject_Object_teardown(object);
    free(object);
    return NULL;
}
cbject_Object * cbject_Object_init(cbject_Object * const object) {
    return object;
}
cbject_Object * cbject_Object_teardown(cbject_Object * object) {
    return cbject_callMethodOfObject(cbject_Object, teardown, object);
}
static cbject_Object * teardown(cbject_Object * object) {
    (void)(object);
    return NULL;
}
cbject_Object * cbject_Object_copy(cbject_Object const * const object, cbject_Object * const copyObject) {
    return cbject_callMethodOfObject(cbject_Object, copy, object, copyObject);
}
static cbject_Object * copy(cbject_Object const * const object, cbject_Object * const copyObject) {
    memcpy(copyObject, object, object->objectClass->objectSize);
    return copyObject;
}
bool cbject_Object_equals(cbject_Object const * const object, cbject_Object const * const otherObject) {
    return cbject_callMethodOfObject(cbject_Object, equals, object, otherObject);
}
static bool equals(cbject_Object const * const object, cbject_Object const * const otherObject) {
    return object == otherObject;
}
uint64_t cbject_Object_hashCode(cbject_Object const * const object) {
    return cbject_callMethodOfObject(cbject_Object, hashCode, object);
}
static uint64_t hashCode(cbject_Object const * const object) {
    return (uint64_t)object;
}
bool cbject_Object_isOfClass(cbject_Object const * const object, cbject_ObjectClass const * const objectClass) {
    bool isOfClass = false;
    cbject_ObjectClass const * cbject_ObjectClass = cbject_getClassOfObject(object);
    while (cbject_ObjectClass != NULL) {
        if (cbject_ObjectClass == objectClass) {
            isOfClass = true;
            cbject_ObjectClass = NULL;
        } else {
            cbject_ObjectClass = cbject_ObjectClass->superClass;
        }
    }
    return isOfClass;
}
