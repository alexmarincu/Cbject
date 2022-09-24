#include "Trait.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>
Trait_Interface const * Trait_Interface_(void) {
    static Trait_Interface interface;
    doOnce_ {
        interface = (Trait_Interface){
            .offset = 0
        };
    }
    return &interface;
}
Trait * Trait_init(Trait * const me) {
    me->offset = 0;
    me->interfaceOffset = 0;
    return me;
}