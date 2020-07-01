#include "RectangleSuper.h"
override_fun(mUInt32, Shape, area);

class_init(
    Shape_init((mShape) me, (ShapeInitParams Ptr) params);
    bind_virtual_functions(
        override_virtual_fun(mUInt32, Shape, area));
    me->width = params->width;
    me->height = params->height);

default_set_get(UInt32, width);
default_set_get(UInt32, height);

fun(mUInt32, test, UInt32 a) { return a; }
override_fun(mUInt32, Shape, area) { return me->width * me->height; }
