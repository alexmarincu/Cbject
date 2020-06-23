#include "CObjectSuper.h"

_UInt8 super_CObject_objectSize(CObject me)
{
    return sizeof(*me);
}

_UInt8 CObject_objectSize(CObject me)
{
    return me->vT->objectSize(me);
}

_Boolean CObject_isInitialized(CObject me)
{
    return me->isInitialized;
}

Void CObject_init(_CObject me)
{
    static CObjectVT const vT = {super_CObject_objectSize};
    me->vT = &vT;
    me->isInitialized = true;
}
