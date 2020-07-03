#include "RectangleSuper.h"
override_fun(mFloat, Shape, area);

class_init(
    Shape_init((mShape) me, (ShapeInitParams Ptr) params);
    bind_virtual_functions(
        bind_override_fun(mFloat, Shape, area););
    me->width = params->width;
    me->height = params->height;);

default_set_get(UInt32, width);
default_set_get(UInt32, height);

fun(mUInt32, test, UInt32 a) { return a; }
override_fun(mFloat, Shape, area) { return me->width * me->height; }
