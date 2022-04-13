#include "Object.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>

/**
 *
 */
Object * Object_deinit(Object * me) {
    return call_(Object, deinit, me);
}
static Object * deinit(Object * me) {
    return NULL;
}

/**
 *
 */
Object * Object_copy(Object const * const me) {
    return call_(Object, copy, me);
}
static Object * copy(Object const * const me) {
    Object * object = Object_alloc(classOf_(me));
    assert_(object);
    object = memcpy(object, me, objectSizeOf_(me));
    return object;
}

/**
 *
 */
bool Object_equals(Object const * const me, Object const * const other) {
    return call_(Object, equals, me, other);
}
static bool equals(Object const * const me, Object const * const other) {
    return me == other;
}

/**
 *
 */
uint64_t Object_hashCode(Object const * const me) {
    return call_(Object, hashCode, me);
}
static uint64_t hashCode(Object const * const me) {
    return (uint64_t)me;
}

/**
 *
 */
bool Object_isOfClass(Object const * const me, Class const * const targetClass) {
    bool isOfClass = true;
    Class const * cls = me->cls;

    if (targetClass != ObjectClass_()) {
        while ((isOfClass == true) && (cls != targetClass)) {
            cls = cls->superClass;

            if (cls == NULL) {
                isOfClass = false;
            }
        }
    }

    return isOfClass;
}

/**
 *
 */
Object * Object_cast(Object * const me, Class const * const cls) {
    assert_(Object_isOfClass(objectOf_(me), cls));
    return objectOf_(me);
}

/**
 *
 */
Object * Object_alloc(Class const * const cls) {
    Object * me = toObject_(calloc(1, cls->objectSize));
    assert_(me);
    return me;
}

/**
 *
 */
Object * Object_dealloc(Object * const me) {
    deinit_(me);
    free(me);
    return NULL;
}

/**
 *
 */
Object * Object_init(Object * const me, Class const * const cls) {
    me->offset = 0;
    me->cls = cls;
    return me;
}

/**
 *
 */
ObjectOps const * ObjectOps_(void) {
    static ObjectOps const ops = {
        .deinit = deinit,
        .copy = copy,
        .equals = equals,
        .hashCode = hashCode
    };

    return &ops;
}

/**
 *
 */
Class const * ObjectClass_(void) {
    static Class cls;

    doOnce_ {
        Class_init(&cls, "Object", sizeof(Object), toAny_(ObjectOps_()), NULL);
    }

    return &cls;
}