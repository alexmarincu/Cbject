#include "super_Shape.h"
#include <stdio.h>

#define Class_ Shape
#define super_Class_ Obj

abstract_class_setup({ bind_virtual_functions(area, draw); });
init({ this_->origin = params->origin; });
terminate({});

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

fun(Void, dummy, ()) { printf("Shape dummy\n"); }

#undef super_Class_
#undef Class_
