#ifndef CLASS_H
#define CLASS_H
#include "Interface.h"

/**
 * @brief Class
 */
typedef struct Class Class;
struct Class {
    extend_(Interface);
    char const * name;
    size_t objectSize;
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
    Any const * const ops,
    char const * const name,
    size_t const objectSize,
    Class const * const superClass
);

/**
 * @brief
 */
#define initClass_(me, className, superClass) \
    Class_init(toClass_(me), toAny_(className##Ops_()), #className, sizeof(className), toClass_(superClass))

#endif // CLASS_H
