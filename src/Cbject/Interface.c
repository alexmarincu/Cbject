#include "Interface.h"

Interface * Interface_init(
    Interface * const me,
    size_t const offset,
    Any const * const ops
) {
    initType_(me, offset);
    me->ops = ops;
    return me;
}
