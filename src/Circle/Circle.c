#include "CircleSuper.h"
#include <stdio.h>

default_set(UInt32, radius);
default_get(UInt32, radius);

override_fun(_UInt32, Shape, area);
override_fun(Void, Shape, draw);

class_init()
{
    super_class_init((ShapeInitParams ptr) params);

    bind_virtual_functions(
        override_virtual_fun(_UInt32, Shape, area),
        override_virtual_fun(Void, Shape, draw));

    me->radius = params->radius;
}

override_fun(Void, Shape, draw)
{
    (Void) me;
    printf("Circle draw");
}

override_fun(_UInt32, Shape, area) { return me->radius * me->radius * 3; }