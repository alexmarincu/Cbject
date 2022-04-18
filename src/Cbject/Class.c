#include "Class.h"

Class * Class_init(
    Class * const me,
    Interface const * const interface,
    char const * const name,
    size_t const objectSize,
    Class const * const superClass
) {
    initClassMixin_(me, interface);
    me->name = name;
    me->objectSize = objectSize;
    me->superClass = superClass;
    return me;
}