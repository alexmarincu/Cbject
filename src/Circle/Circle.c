#include "CircleSuper.h"
#include <stdio.h>

#undef Class
#define Class Circle
#undef SuperClass
#define SuperClass Shape

constants(
    (Float, pi = 3.14),
    (Float, anotherPi = 3.14));

private_constants(
    (Float, privatePi = 3.14),
    (Float, anotherPrivatePi = 3.14));

override_functions(
    (Float, Shape, area, ()),
    (Void, Shape, draw, (UInt8 const a)));

class_init({
    Shape_init((Shape * const) me, (ShapeInitParams *) params);

    setup_virtual_functions({
        bind_override_functions(
            (Float, Shape, area, ()),
            (Void, Shape, draw, (UInt8 const a)));
    });

    me->radius = params->radius;
});

default_set_get(UInt32, radius);

override_fun(Void, Shape, draw, (UInt8 const a))
{
    super_Shape_draw((Shape *) me, a);
    printf("Circle draw\n");
}

override_fun(Float, Shape, area, ()) { return me->radius * me->radius * Circle_pi; }