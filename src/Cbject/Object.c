#include "Object.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>
static Object * teardown(Object * object);
static Object * copy(Object const * const object, Object * const copyObject);
static bool equals(Object const * const object, Object const * const otherObject);
static uint64_t hashCode(Object const * const object);
Object_Class const * Object_Class_(void) {
    static Object_Class class = {
        .objectSize = sizeof(Object),
        .superClass = NULL,
        .teardown = teardown,
        .copy = copy,
        .equals = equals,
        .hashCode = hashCode
    };
    return &class;
}
Object * Object_alloc(Object_Class const * const class) {
    Object * object = to_(Object, calloc(1, class->objectSize));
    assert_(object);
    return object;
}
Object * Object_dealloc(Object * const object) {
    teardown_(object);
    free(object);
    return NULL;
}
Object * Object_init(Object * const object) {
    object->class = class_(Object);
    return object;
}
Object * Object_teardown(Object * object) {
    return objectMethodCall_(Object, teardown, object);
}
static Object * teardown(Object * object) {
    ignore_(object);
    return NULL;
}
Object * Object_copy(Object const * const object, Object * const copyObject) {
    return objectMethodCall_(Object, copy, object, copyObject);
}
static Object * copy(Object const * const object, Object * const copyObject) {
    memcpy(copyObject, object, object->class->objectSize);
    return copyObject;
}
bool Object_equals(Object const * const object, Object const * const otherObject) {
    return objectMethodCall_(Object, equals, object, otherObject);
}
static bool equals(Object const * const object, Object const * const otherObject) {
    return object == otherObject;
}
uint64_t Object_hashCode(Object const * const object) {
    return objectMethodCall_(Object, hashCode, object);
}
static uint64_t hashCode(Object const * const object) {
    return (uint64_t)object;
}
bool Object_isOfClass(Object const * const object, Object_Class const * const targetClass) {
    bool isOfClass = true;
    Object_Class const * class = object->class;
    if (targetClass != to_(Object_Class, class_(Object))) {
        while ((isOfClass == true) && (class != targetClass)) {
            class = class->superClass;
            if (class == NULL) {
                isOfClass = false;
            }
        }
    }
    return isOfClass;
}
