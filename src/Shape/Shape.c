#include "ShapeSuper.h"
#include <stdio.h>

abstract_class_init(
    bind_virtual_functions(
        bind_virtual_fun(area);
        bind_virtual_fun(draw));
    me->origin = params->origin);

default_set_get(Point, origin);

// virtual_call(mUInt32, area) { call(area); }
default_fun(
    call(area),
    mUInt32, area)
{
    (Void) me;
    return 0;
}

// virtual_call(Void, draw, UInt8 a) { call(draw, a); }
default_fun(
    call(draw, a),
    Void, draw, UInt8 a)
{
    (Void) me;
    printf("Shape draw\n");
}