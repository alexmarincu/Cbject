#include "Class.h"

Class * Class_init(
    Class * const me,
    Any const * const ops,
    char const * const name,
    size_t const objectSize,
    Class const * const superClass
) {
    initInterface_(me, 0, ops);
    me->name = name;
    me->objectSize = objectSize;
    me->superClass = superClass;
    return me;
}