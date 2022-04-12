#include "Interface.h"

/**
 *
 */
Interface * Interface_init(
    Interface * const me,
    Object * const object,
    Any const * const ops
) {
    me->object = object;
    me->ops = ops;
    return me;
}
