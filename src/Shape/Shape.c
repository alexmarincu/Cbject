#include "ShapeSuper.h"

_default_fun(_UInt32, area);
override_fun(CObject, _UInt8, objectSize);

default_set(Point, origin);
default_get(Point, origin);

override_fun(CObject, _UInt8, objectSize)
{
    return sizeof(*me);
}

default_fun(_UInt32, area)
{
    (Void) me;
    return 0;
}

Void Shape_init(Shape me, ShapeInitParams Ref params)
{
    static ShapeVT const vT = {
        {(_UInt8(Ref)(CObject me)) override_CObject_objectSize},
        default_Shape_area};

    CObject_init((_CObject) me);
    ((_CObject) me)->vT = (CObjectVT Ref) &vT;
    ((_Shape) me)->origin.x = params->origin.x;
    ((_Shape) me)->origin.y = params->origin.y;
}

Void Shape_reset(Shape me)
{
    ((_Shape)me)->origin.x = 0;
    ((_Shape)me)->origin.y = 0;
    CObject_reset((_CObject) me);
}

