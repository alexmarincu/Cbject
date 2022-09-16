#include "Object.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>
static Object * deinit(Object * me);
static Object * copy(Object const * const me);
static bool equals(Object const * const me, Object const * const other);
static uint64_t hashCode(Object const * const me);
Object_Class const * Object_Class_(void) {
    static Object_Class cls;
    doOnce_ {
        Class_init(
            (Class *)&cls,
            (Operations *)Object_Operations_(),
            "Object",
            sizeof(Object),
            NULL
        );
    }
    return &cls;
}
Object_Operations const * Object_Operations_(void) {
    static Object_Operations const operations = {
        .deinit = deinit,
        .copy = copy,
        .equals = equals,
        .hashCode = hashCode
    };
    return &operations;
}
Object * Object_alloc(Class const * const cls) {
    Object * object = (Object *)calloc(1, cls->objectSize);
    assert_(object);
    return object;
}
Object * Object_dealloc(Object * const me) {
    deinit_(me);
    free(me);
    return NULL;
}
Object * Object_init(Object * const me, Type const * const type) {
    me->type = type;
    return me;
}
Object * Object_deinit(Object * me) {
    return call_(Object, deinit, me);
}
static Object * deinit(Object * me) {
    (void)me;
    return NULL;
}
Object * Object_copy(Object const * const me) {
    return call_(Object, copy, me);
}
static Object * copy(Object const * const me) {
    Object * object = Object_alloc(classOf_(me));
    assert_(object);
    object = memcpy(object, me, objectSizeOf_(me));
    return object;
}
bool Object_equals(Object const * const me, Object const * const other) {
    return call_(Object, equals, me, other);
}
static bool equals(Object const * const me, Object const * const other) {
    return me == other;
}
uint64_t Object_hashCode(Object const * const me) {
    return call_(Object, hashCode, me);
}
static uint64_t hashCode(Object const * const me) {
    return (uint64_t)me;
}
bool Object_isOfClass(Object const * const me, Class const * const targetClass) {
    bool isOfClass = true;
    Class const * cls = classOf_(me);
    if (targetClass != (Class *)Object_Class_()) {
        while ((isOfClass == true) && (cls != targetClass)) {
            cls = cls->superClass;
            if (cls == NULL) {
                isOfClass = false;
            }
        }
    }
    return isOfClass;
}
void Object_setType(Object * const me, Type const * const type) {
    me->type = type;
}
