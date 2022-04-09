#include "Interface.h"

/**
 * @brief
 * @param me
 * @param object
 * @param operations
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
