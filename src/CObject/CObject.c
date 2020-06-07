#include "CObjectSuper.h"

//================================================
static _UInt8 default_CObject_objectSize(CObject me);

//================================================
static _UInt8 default_CObject_objectSize(CObject me)
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

//================================================
Void CObject_init(_CObject me)
{
    static CObjectVT const vT = {CObject_objectSize};
    me->vT = &vT;
    me->isInitialized = true;
}

Void CObject_reset(_CObject me)
{
    me->vT = null;
    me->isInitialized = false;
}
