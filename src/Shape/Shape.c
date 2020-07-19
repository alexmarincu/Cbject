#include "super_Shape.h"
#include <stdio.h>

#undef Class_
#define Class_ Shape
#undef super_Class_
#define super_Class_ CO

abstract_class_setup({ bind_virtual_functions(area, draw); });
init({ this_->origin = params->origin; });

default_set_get(Point, origin);

virtual_fun(Float, area, (), ())
{
    (Void) this_;
    return 0;
}

virtual_fun(Void, draw, (UInt8 const a), (a))
{
    (Void) this_;
    printf("Shape draw\n");
}

fun(Void, dummy, ())
{
    printf("Shape dummy\n");
}