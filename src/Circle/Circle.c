#include "CircleSuper.h"

default_set(UInt32, radius);
default_get(UInt32, radius);

override_fun(_UInt32, Shape, area);

class_init()
{
    super_class_init((ShapeInitParams ptr) params);

    bind_virtual_functions(
        override_virtual_fun(_UInt32, Shape, area));

    me->radius = params->radius;
}

static _UInt32 override_Shape_area(Circle me) { return me->radius * me->radius * 3; }