#include "Trait.h"

Trait * Trait_init(
    Trait * const me,
    size_t const offset,
    Interface const * const interface
) {
    initType_(me, offset);
    me->interface = interface;
    return me;
}
