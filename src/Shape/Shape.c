#include "ShapeSuper.h"

static _UInt32 default_Shape_area(Shape me);
static _UInt8 override_CObject_objectSize(Shape me);

Void Shape_setOrigin(_Shape me, Point origin)
{
    me->origin = origin;
}

_Point Shape_getOrigin(Shape me)
{
    return me->origin;
}

static _UInt32 default_Shape_area(Shape me)
{
    (Void) me;
    return 0;
}

_UInt32 Shape_area(Shape me)
{
    return ((ShapeVT Ref)((CObject) me)->vT)->area(me);
}

Void Shape_init(_Shape me, ShapeInitParams Ref params)
{
    static ShapeVT const vT = {
        {(_UInt8(Ref)(CObject me)) override_CObject_objectSize},
        default_Shape_area};

    CObject_init((_CObject) me);
    ((_CObject) me)->vT = (CObjectVT Ref) &vT;
    me->origin.x = params->origin.x;
    me->origin.y = params->origin.y;
}

Void Shape_reset(_Shape me)
{
    me->origin.x = 0;
    me->origin.y = 0;
    CObject_reset((_CObject) me);
}

static _UInt8 override_CObject_objectSize(Shape me)
{
    return sizeof(*me);
}