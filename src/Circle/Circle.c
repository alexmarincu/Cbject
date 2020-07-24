#include "super_Circle.h"
#include <stdio.h>

#define Class_ Circle
#define super_Class_ Shape

constants(
    (Float, pi = 3.14),
    (Float, anotherPi = 3.14));

private_constants(
    (Float, privatePi = 3.14),
    (Float, anotherPrivatePi = 3.14));

class_pool_size(10);

class_setup({
    bind_virtual_fun(rotate);
    bind_override_functions(
        (Float, Shape, area, ()),
        (Void, Shape, draw, (UInt8 const a)));
});

init({
    Shape_init((Shape * const) this_, (ShapeInitParams *) params);
    this_->radius = params->radius;
});

clear({ Shape_clear((Shape * const) this_); });

default_set_get(UInt32, radius);

override_fun(Void, Shape, draw, (UInt8 const a))
{
    super_Shape_draw((Shape *) this_, a);
    printf("Circle draw\n");
}

override_fun(Float, Shape, area, ()) { return this_->radius * this_->radius * Circle_pi; }
virtual_fun(Void, rotate, (), ()) { printf("Rotate clockwise\n"); }

#undef super_Class_
#undef Class_
