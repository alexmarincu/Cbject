#include "Class.h"

/**
 * @brief
 * @param me
 * @param name
 * @param objectSize
 * @param operations
 * @param superClass
 * @return Class*
 */
Class * Class_init(
    Class * const me,
    char const * const name,
    size_t const objectSize,
    Any const * const operations,
    Class const * const superClass
) {
    me->name = name;
    me->objectSize = objectSize;
    me->operations = operations;
    me->superClass = superClass;
    return me;
}