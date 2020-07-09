#include "CObjectSuper.h"

UInt8 super_CObject_objectSize(CObject const * const me) { return sizeof(*me); }
UInt8 CObject_objectSize(CObject const * const me) { return me->vT->objectSize(me); }

Void CObject_init(CObject * const me)
{
    static CObjectVT const vT = {.objectSize = super_CObject_objectSize};
    me->vT = &vT;
}
