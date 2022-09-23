#include "Module.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>
Module_Interface const * Module_Interface_(void) {
    static Module_Interface interface;
    doOnce_ {
        interface = (Module_Interface){
            .offset = 0
        };
    }
    return &interface;
}
Module * Module_init(Module * const me) {
    me->offset = 0;
    me->interfaceOffset = 0;
    return me;
}