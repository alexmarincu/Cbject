#include "cbject_Trait.h"
#include <stdlib.h>
#include <string.h>
cbject_TraitInterface const * cbject_TraitInterface_getInstance(void) {
    static cbject_TraitInterface traitInterface = {
        .name = "Trait",
        .traitOffset = 0
    };
    return &traitInterface;
}
cbject_Trait * cbject_Trait_init(cbject_Trait * const trait) {
    trait->object = NULL;
    trait->interface = NULL;
    return trait;
}