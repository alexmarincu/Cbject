#include "Class.h"

/**
 *
 */
Class * Class_init(
    Class * const me,
    char const * const name,
    size_t const objectSize,
    Any const * const ops,
    Class const * const superClass
) {
    me->name = name;
    me->objectSize = objectSize;
    me->ops = ops;
    me->superClass = superClass;
    return me;
}