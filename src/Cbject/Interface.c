#include "Interface.h"

/**
 *
 */
Interface * Interface_init(
    Interface * const me,
    Object * const object,
    Any const * const operations
) {
    me->object = object;
    me->operations = operations;
    return me;
}
