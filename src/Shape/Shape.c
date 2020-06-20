#include "ShapeSuper.h"

default_set(Point, origin);
default_get(Point, origin);

default_fun(_UInt32, area)
{
    (Void) me;
    return 0;
}

abstract_class_init()
{
    bind_virtual_functions(
        default_Shape_area);

    me->origin = params->origin;
}
