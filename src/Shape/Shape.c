#include "ShapeSuper.h"
#include <stdio.h>

default_set(Point, origin);
default_get(Point, origin);

default_fun(_UInt32, area)
{
    (Void) me;
    return 0;
}

default_fun(Void, draw)
{
    (Void) me;
    printf("Shape draw\n");
}

abstract_class_init()
{
    bind_virtual_functions(
        super_Shape_area,
        super_Shape_draw);
        
    me->origin = params->origin;
}
