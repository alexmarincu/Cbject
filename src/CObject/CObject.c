#include "CObjectSuper.h"

UInt8 super_CO_objectSize(CO const * const me) { return sizeof(*me); }
UInt8 CO_objectSize(CO const * const me) { return me->thisClass->objectSize(me); }

Void CO_init(CO * const me)
{
    static COClass const thisClass = {.objectSize = super_CO_objectSize};
    me->thisClass = &thisClass;
}
