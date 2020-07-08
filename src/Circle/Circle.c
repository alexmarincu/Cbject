#include "CircleSuper.h"
#include <stdio.h>

#undef class
#define class Circle
#undef super_class
#define super_class Shape

constants(
    (Float, pi = 3.14),
    (Float, anotherPi = 3.14));

private_constants(
    (Float, privatePi = 3.14),
    (Float, anotherPrivatePi = 3.14));

override_fun(mFloat, Shape, area, ());
override_fun(Void, Shape, draw, (UInt8 a));

class_init({
    Shape_init((mShape pt) me, (ShapeInitParams pt) params);

    setup_virtual_functions({
        override_functions(
            (mFloat, Shape, area, ()),
            (Void, Shape, draw, (UInt8 a)));
    });

    me->radius = params->radius;
});

default_set_get(UInt32, radius);

override_fun(Void, Shape, draw, (UInt8 a))
{
    super_Shape_draw((Shape pt) me, a);
    printf("Circle draw\n");
}

override_fun(mFloat, Shape, area, ()) { return me->radius * me->radius * Circle_pi; }