#ifndef CLASS_H
#define CLASS_H
#include "Types.h"

/**
 * @brief
 */
typedef struct Class Class;
struct Class {
    char const * name;
    size_t objectSize;
    Any const * ops;
    Class const * superClass;
};

/**
 * @brief
 * @param me
 * @param name
 * @param objectSize
 * @param ops
 * @param superClass
 * @return Class*
 */
Class * Class_init(
    Class * const me,
    char const * const name,
    size_t const objectSize,
    Any const * const ops,
    Class const * const superClass
);

/**
 * @brief
 */
#define initClass_(me, className, superClassName) \
    Class_init(me, #className, sizeof(className), toAny_(className##Ops_()), superClassName##Class_())

#endif // CLASS_H
