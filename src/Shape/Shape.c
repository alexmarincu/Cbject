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
    CObject_init((_CObject) me);

    bind_virtual_functions(
        bind_virtual_fun(area);
        bind_virtual_fun(draw));

    me->origin = params->origin;
}
