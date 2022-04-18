#include "Mixin.h"

Mixin * Mixin_init(
    Mixin * const me,
    size_t const offset,
    Interface const * const interface
) {
    initType_(me, offset);
    me->interface = interface;
    return me;
}
