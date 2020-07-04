#include "ShapeSuper.h"
#include <stdio.h>

#undef class
#define class Shape
#undef super_class
#define super_class CObject

static super_fun(mFloat, area);

abstract_class_init(
    bind_virtual_functions(
        bind_virtual_fun(area);
        bind_virtual_fun(draw););
    me->origin = params->origin;);

default_set_get(Point, origin);

fun(mFloat, area) { virtual_call(area); }
static super_fun(mFloat, area)
{
    (Void) me;
    return 0;
}

fun(Void, draw, UInt8 a) { virtual_call(draw, a); }
super_fun(Void, draw, UInt8 a)
{
    (Void) me;
    printf("Shape draw\n");
}