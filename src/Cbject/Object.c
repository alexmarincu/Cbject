#include "Object.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>

/**
 *
 */
void Object_finalize(Object * me) {
    return call_(Object, finalize, me);
}
static void finalize(Object * me) {
}

/**
 *
 */
Object * Object_copy(Object const * const me) {
    return call_(Object, copy, me);
}
static Object * copy(Object const * const me) {
    Object * object = Object_new(classOf_(me));
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
    assert_(Object_isOfClass(me, cls) == true);
    return me;
}

/**
 *
 */
Object * Object_new(Class const * const cls) {
    Object * me = toObject_(calloc(1, cls->objectSize));
    assert_(me);
    return me;
}

/**
 *
 */
Object * Object_delete(Object * const me) {
    finalize_(me);
    free(me);
    return NULL;
}

/**
 *
 */
Object * Object_init(Object * const me, Class const * const cls) {
    me->cls = cls;
    return me;
}

/**
 *
 */
ObjectOperations const * ObjectOperations_(void) {
    static ObjectOperations const operations = {
        .finalize = finalize,
        .copy = copy,
        .equals = equals,
        .hashCode = hashCode
    };

    return &operations;
}

/**
 *
 */
Class const * ObjectClass_(void) {
    static Class cls;

    doOnce_ {
        Class_init(&cls, "Object", sizeof(Object), toAny_(ObjectOperations_()), NULL);
    }

    return &cls;
}