#include "super_Shape.h"
#include <stdio.h>

#undef Class_
#define Class_ Shape
#undef SuperClass
#define SuperClass CO

abstract_class_setup({ bind_virtual_functions(area, draw); });
init({ this_->origin = params->origin; });

default_set_get(Point, origin);

fun(Float, area, ()) { virtual_call(area, ()); }
virtual_fun(Float, area, ())
{
    (Void) this_;
    return 0;
}

fun(Void, draw, (UInt8 const a)) { virtual_call(draw, (a)); }
virtual_fun(Void, draw, (UInt8 const a))
{
    (Void) this_;
    printf("Shape draw\n");
}

fun(Void, dummy, ())
{
    printf("Shape dummy\n");
}