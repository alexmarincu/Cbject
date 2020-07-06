#include "RectangleSuper.h"

#undef class
#define class Rectangle
#undef super_class
#define super_class Shape

override_fun(mFloat, Shape, area, ());

class_init(
    Shape_init((mShape Pt) me, (ShapeInitParams Pt) params);
    bind_virtual_functions(
        bind_override_fun(mFloat, Shape, area););
    me->width = params->width;
    me->height = params->height;);

default_set_get(UInt32, width);
default_set_get(UInt32, height);

fun(mUInt32, test, (UInt32 a)) { return a; }
override_fun(mFloat, Shape, area, ()) { return me->width * me->height; }
