#include "CircleSuper.h"
#include <stdio.h>

static Float pi = 3.14;

default_set_get(UInt32, radius);
override_fun(mFloat, Shape, area);
override_fun(Void, Shape, draw, UInt8 a);

class_init(
    Shape_init((mShape) me, (ShapeInitParams Ptr) params);

    bind_virtual_functions(
        bind_override_fun(mFloat, Shape, area);
        bind_override_fun(Void, Shape, draw, UInt8 a));

    me->radius = params->radius);

override_fun(Void, Shape, draw, UInt8 a)
{
    (Void) me;
    super_Shape_draw((Shape) me, a);
    printf("Circle draw\n");
}

override_fun(mFloat, Shape, area) { return me->radius * me->radius * pi; }