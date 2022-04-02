#include "Object.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief
 *
 * @param this_
 */
void Object_finalize(Object * this_) {
    return call_(Object, finalize, this_);
}
static void finalize(Object * this_) {
}

/**
 * @brief
 *
 * @param this_
 * @return Object*
 */
Object * Object_copy(Object const * const this_) {
    return call_(Object, copy, this_);
}
static Object * copy(Object const * const this_) {
    Object * object = Object_new(classOf_(this_));
    assert_(object);
    object = memcpy(object, this_, objectSizeOf_(this_));
    return object;
}

/**
 * @brief
 *
 * @param this_
 * @param other
 * @return true
 * @return false
 */
bool Object_equals(Object const * const this_, Object const * const other) {
    return callWithArgs_(Object, equals, this_, other);
}
static bool equals(Object const * const this_, Object const * const other) {
    return this_ == other;
}

/**
 * @brief
 *
 * @param this_
 * @return uint64_t
 */
uint64_t Object_hashCode(Object const * const this_) {
    return call_(Object, hashCode, this_);
}
static uint64_t hashCode(Object const * const this_) {
    return (uint64_t)this_;
}

/**
 * @brief
 *
 * @param this_
 * @param class_
 * @return true
 * @return false
 */
bool Object_isOfClass(Object const * const this_, Class const * const targetClass) {
    bool isOfClass = true;
    Class const * class_ = this_->class_;

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
 *
 * @param this_
 * @param class_
 * @return Object*
 */
Object * Object_cast(Object * const this_, Class const * const class_) {
    assert_(isOfClass_(this_, class_) == true);
    return this_;
}

/**
 * @brief
 *
 * @param class_
 * @return Object*
 */
Object * Object_new(Class const * const class_) {
    Object * this_ = objectOf_(calloc(1, class_->objectSize));
    assert_(this_);
    return this_;
}

/**
 * @brief
 *
 * @param this_
 */
void Object_delete(Object * const this_) {
    finalize_(this_);
    free(this_);
}

/**
 * @brief
 *
 * @param this_
 * @param class_
 */
Object * Object_init(Object * const this_, Class const * const class_) {
    this_->class_ = class_;
}

/**
 * @brief
 *
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
 *
 * @return Class const*
 */
Class const * ObjectClass_(void) {
    static Class class_;

    doOnce_({
        initClass_(&class_, Object, NULL);
    });

    return &class_;
}