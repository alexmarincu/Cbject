#include "RectangleSuper.h"

default_set(UInt32, width);
default_get(UInt32, width);
default_set(UInt32, height);
default_get(UInt32, height);

fun(_UInt32, test, UInt32 a)
{
    return a;
}

override_fun(_UInt32, Shape, area);

class_init()
{
    super_class_init((ShapeInitParams ptr) params);

    bind_virtual_functions(
        override_virtual_fun(_UInt32, Shape, area),
        super_Shape_draw);

    me->width = params->width;
    me->height = params->height;
}




override_fun(_UInt32, Shape, area) { return me->width * me->height; }
