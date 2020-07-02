#include "CircleSuper.h"
#include <stdio.h>

default_set_get(UInt32, radius);
override_fun(mUInt32, Shape, area);
override_fun(Void, Shape, draw, UInt8 a);

class_init(
    Shape_init((mShape) me, (ShapeInitParams Ptr) params);

    bind_virtual_functions(
        bind_override_fun(mUInt32, Shape, area);
        bind_override_fun(Void, Shape, draw, UInt8 a));

    me->radius = params->radius);

override_fun(Void, Shape, draw, UInt8 a)
{
    (Void) me;
    super_Shape_draw((Shape) me, a);
    printf("Circle draw");
}

override_fun(mUInt32, Shape, area) { return me->radius * me->radius * 3; }