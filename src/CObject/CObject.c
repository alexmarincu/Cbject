#include "CObjectSuper.h"

mUInt8 super_CObject_objectSize(CObject me) { return sizeof(*me); }
mUInt8 CObject_objectSize(CObject me) { return me->vT->objectSize(me); }
mBoolean CObject_isInitialized(CObject me) { return me->isInitialized; }

Void CObject_init(mCObject me)
{
    static CObjectVT vT = {super_CObject_objectSize};
    me->vT = &vT;
    me->isInitialized = true;
}
