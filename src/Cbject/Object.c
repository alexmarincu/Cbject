#include "Object.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>
static Object * teardown(Object * me);
static Object * copy(Object const * const me, Object * const object);
static bool equals(Object const * const me, Object const * const other);
static uint64_t hashCode(Object const * const me);
Object_Class const * Object_Class_(void) {
    static Object_Class class;
    doOnce_ {
        class = (Object_Class){
            .objectSize = sizeof(Object),
            .superClass = NULL,
            .teardown = teardown,
            .copy = copy,
            .equals = equals,
            .hashCode = hashCode
        };
    }
    return &class;
}
Object * Object_alloc(Object_Class const * const class) {
    Object * object = to_(Object, calloc(1, class->objectSize));
    assert_(object);
    return object;
}
Object * Object_dealloc(Object * const me) {
    teardown_(me);
    free(me);
    return NULL;
}
Object * Object_init(Object * const me) {
    me->class = class_(Object);
    return me;
}
Object * Object_teardown(Object * me) {
    return objectMethodCall_(Object, teardown, me);
}
static Object * teardown(Object * me) {
    ignore_(me);
    return NULL;
}
Object * Object_copy(Object const * const me, Object * const object) {
    return objectMethodCall_(Object, copy, me, object);
}
static Object * copy(Object const * const me, Object * const object) {
    memcpy(object, me, me->class->objectSize);
    return object;
}
bool Object_equals(Object const * const me, Object const * const other) {
    return objectMethodCall_(Object, equals, me, other);
}
static bool equals(Object const * const me, Object const * const other) {
    return me == other;
}
uint64_t Object_hashCode(Object const * const me) {
    return objectMethodCall_(Object, hashCode, me);
}
static uint64_t hashCode(Object const * const me) {
    return (uint64_t)me;
}
bool Object_isOfClass(Object const * const me, Object_Class const * const targetClass) {
    bool isOfClass = true;
    Object_Class const * class = me->class;
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
