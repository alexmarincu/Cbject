#include "Cbject_Trait.h"
#include <stdlib.h>
#include <string.h>
Cbject_TraitInterface const * Cbject_TraitInterface_instance(void) {
    static Cbject_TraitInterface traitInterface = {
        .name = "Trait",
        .traitOffset = 0
    };
    return &traitInterface;
}
Cbject_Trait * Cbject_Trait_init(Cbject_Trait * const trait) {
    trait->offset = 0;
    trait->interfaceOffset = 0;
    return trait;
}