#include "Trait.h"
#include <stdlib.h>
#include <string.h>
TraitInterface const * TraitInterface_instance(void) {
    static TraitInterface interface = {
        .name = "Trait",
        .traitOffset = 0
    };
    return &interface;
}
Trait * Trait_init(Trait * const trait) {
    trait->offset = 0;
    trait->interfaceOffset = 0;
    return trait;
}