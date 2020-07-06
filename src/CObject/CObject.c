#include "CObjectSuper.h"

mUInt8 super_CObject_objectSize(CObject Pt me) { return sizeof(*me); }
mUInt8 CObject_objectSize(CObject Pt me) { return me->vT->objectSize(me); }

Void CObject_init(mCObject Pt me)
{
    static CObjectVT vT = {.objectSize = super_CObject_objectSize};
    me->vT = &vT;
}
