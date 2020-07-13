#include "CObjectSuper.h"

UInt8 super_CObject_objectSize(CObject const * const me) { return sizeof(*me); }
UInt8 CObject_objectSize(CObject const * const me) { return me->klass->objectSize(me); }

Void CObject_init(CObject * const me)
{
    static CObjectClass const klass = {.objectSize = super_CObject_objectSize};
    me->klass = &klass;
}
