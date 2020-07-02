#include "ShapeSuper.h"
#include <stdio.h>

abstract_class_init(
    bind_virtual_functions(
        bind_virtual_fun(area);
        bind_virtual_fun(draw));
    me->origin = params->origin);

default_set_get(Point, origin);

fun(mUInt32, area) { virtual_call(area); }
virtual_fun(mUInt32, area)
{
    (Void) me;
    return 0;
}

fun(Void, draw, UInt8 a) { virtual_call(draw, a); }
virtual_fun(Void, draw, UInt8 a)
{
    (Void) me;
    printf("Shape draw\n");
}