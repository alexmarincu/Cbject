#ifndef CLASS_H
#define CLASS_H
#include "Types.h"

/**
 * @brief
 *
 */
typedef struct Class Class;
struct Class {
    char const * name;
    size_t objectSize;
    Any const * operations;
    Class const * superClass;
};

/**
 * @brief
 *
 * @param this_
 * @param name
 * @param objectSize
 * @param operations
 * @param superClass
 * @return Class*
 */
Class * Class_init(
    Class * const this_,
    char const * const name,
    size_t const objectSize,
    Any const * const operations,
    Class const * const superClass);

/**
 * @brief
 *
 */
#define initClass_(this_, className, superClass) \
    Class_init(this_, #className, sizeof(className), anyOf_(className##Operations_()), superClass)

#endif // CLASS_H
