#include "Cbject_Object.h"
#include <stdlib.h>
#include <string.h>
static Cbject_Object * teardown(Cbject_Object * object);
static Cbject_Object * copy(Cbject_Object const * const object, Cbject_Object * const copyObject);
static bool equals(Cbject_Object const * const object, Cbject_Object const * const otherObject);
static uint64_t hashCode(Cbject_Object const * const object);
Cbject_ObjectClass const * Cbject_ObjectClass_instance(void) {
    static Cbject_ObjectClass objectClass = {
        .name = "Object",
        .objectSize = sizeof(Cbject_Object),
        .superClass = NULL,
        .teardown = teardown,
        .copy = copy,
        .equals = equals,
        .hashCode = hashCode
    };
    return &objectClass;
}
Cbject_Object * Cbject_Object_alloc(Cbject_ObjectClass const * const objectClass) {
    Cbject_Object * object = Cbject_castTo(Cbject_Object, calloc(1, objectClass->objectSize));
    assert(object);
    return object;
}
Cbject_Object * Cbject_Object_dealloc(Cbject_Object * const object) {
    Cbject_teardown(object);
    free(object);
    return NULL;
}
Cbject_Object * Cbject_Object_init(Cbject_Object * const object) {
    object->objectClass = Cbject_class(Cbject_Object);
    return object;
}
Cbject_Object * Cbject_Object_teardown(Cbject_Object * object) {
    return Cbject_callObjectMethod(Cbject_Object, teardown, object);
}
static Cbject_Object * teardown(Cbject_Object * object) {
    Cbject_ignore(object);
    return NULL;
}
Cbject_Object * Cbject_Object_copy(Cbject_Object const * const object, Cbject_Object * const copyObject) {
    return Cbject_callObjectMethod(Cbject_Object, copy, object, copyObject);
}
static Cbject_Object * copy(Cbject_Object const * const object, Cbject_Object * const copyObject) {
    memcpy(copyObject, object, object->objectClass->objectSize);
    return copyObject;
}
bool Cbject_Object_equals(Cbject_Object const * const object, Cbject_Object const * const otherObject) {
    return Cbject_callObjectMethod(Cbject_Object, equals, object, otherObject);
}
static bool equals(Cbject_Object const * const object, Cbject_Object const * const otherObject) {
    return object == otherObject;
}
uint64_t Cbject_Object_hashCode(Cbject_Object const * const object) {
    return Cbject_callObjectMethod(Cbject_Object, hashCode, object);
}
static uint64_t hashCode(Cbject_Object const * const object) {
    return (uint64_t)object;
}
bool Cbject_Object_isOfClass(Cbject_Object const * const object, Cbject_ObjectClass const * const objectClass) {
    bool isOfClass = false;
    Cbject_ObjectClass const * Cbject_ObjectClass = Cbject_classOf(object);
    while (Cbject_ObjectClass != NULL) {
        if (Cbject_ObjectClass == objectClass) {
            isOfClass = true;
            Cbject_ObjectClass = NULL;
        } else {
            Cbject_ObjectClass = Cbject_ObjectClass->superClass;
        }
    }
    return isOfClass;
}
