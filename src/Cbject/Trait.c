#include "Trait.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>
Trait_Interface const * Trait_Interface_(void) {
    static Trait_Interface interface = {
        .traitOffset = 0
    };
    return &interface;
}
Trait * Trait_init(Trait * const trait) {
    trait->offset = 0;
    trait->interfaceOffset = 0;
    return trait;
}