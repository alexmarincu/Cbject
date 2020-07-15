#include "ShapeSuper.h"
#include <stdio.h>

#undef Class
#define Class Shape
#undef SuperClass
#define SuperClass CO

abstract_class_init({
    setup_virtual_functions({ bind_virtual_functions(area, draw); });
    _this->origin = params->origin;
});

default_set_get(Point, origin);

fun(Float, area, ()) { virtual_call(area, ()); }
virtual_fun(Float, area, ())
{
    (Void) _this;
    return 0;
}

fun(Void, draw, (UInt8 const a)) { virtual_call(draw, (a)); }
virtual_fun(Void, draw, (UInt8 const a))
{
    (Void) _this;
    printf("Shape draw\n");
}

fun(Void, dummy, ())
{
    printf("Shape dummy\n");
}