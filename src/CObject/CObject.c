#include "CObjectSuper.h"

mUInt8 super_CObject_objectSize(CObject pt me) { return sizeof(*me); }
mUInt8 CObject_objectSize(CObject pt me) { return me->vT->objectSize(me); }

Void CObject_init(mCObject pt me)
{
    static CObjectVT vT = {.objectSize = super_CObject_objectSize};
    me->vT = &vT;
}
