#include "Object.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief
 * @param me
 */
void Object_finalize(Object * me) {
    return call_(Object, finalize, me);
}
static void finalize(Object * me) {
}

/**
 * @brief
 * @param me
 * @return Object*
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
 * @brief
 * @param me
 * @param other
 * @return true
 * @return false
 */
bool Object_equals(Object const * const me, Object const * const other) {
    return call_(Object, equals, me, other);
}
static bool equals(Object const * const me, Object const * const other) {
    return me == other;
}

/**
 * @brief
 * @param me
 * @return uint64_t
 */
uint64_t Object_hashCode(Object const * const me) {
    return call_(Object, hashCode, me);
}
static uint64_t hashCode(Object const * const me) {
    return (uint64_t)me;
}

/**
 * @brief
 * @param me
 * @param class_
 * @return true
 * @return false
 */
bool Object_isOfClass(Object const * const me, Class const * const targetClass) {
    bool isOfClass = true;
    Class const * class_ = me->class_;

    if (targetClass != ObjectClass_()) {
        while ((isOfClass == true) && (class_ != targetClass)) {
            class_ = class_->superClass;

            if (class_ == NULL) {
                isOfClass = false;
            }
        }
    }

    return isOfClass;
}

/**
 * @brief
 * @param me
 * @param class_
 * @return Object*
 */
Object * Object_cast(Object * const me, Class const * const class_) {
    assert_(Object_isOfClass(me, class_) == true);
    return me;
}

/**
 * @brief
 * @param class_
 * @return Object*
 */
Object * Object_new(Class const * const class_) {
    Object * me = objectOf_(calloc(1, class_->objectSize));
    assert_(me);
    return me;
}

/**
 * @brief
 * @param me
 */
void Object_delete(Object * const me) {
    finalize_(me);
    free(me);
}

/**
 * @brief Initializes an object
 * @param me The object
 * @param class_ The class
 * @return Object* The initialized object
 */
Object * Object_init(Object * const me, Class const * const class_) {
    me->class_ = class_;
    return me;
}

/**
 * @brief
 * @return ObjectOperations const*
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
 * @brief
 * @return Class const*
 */
Class const * ObjectClass_(void) {
    static Class class_;

    doOnce_({
        initClass_(&class_, Object, NULL);
    });

    return &class_;
}