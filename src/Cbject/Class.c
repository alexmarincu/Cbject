#include "Class.h"

Class * Class_init(
    Class * const me,
    Operations const * const operations,
    char const * const name,
    size_t const objectSize,
    Class const * const superClass
) {
    Type_init((Type *)me, 0, operations);
    me->name = name;
    me->objectSize = objectSize;
    me->superClass = superClass;
    return me;
}