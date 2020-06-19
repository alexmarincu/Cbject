#include "ShapeSuper.h"

default_set(Point, origin);
default_get(Point, origin);

default_fun(_UInt32, area)
{
    (Void) me;
    return 0;
}

class_init(Point origin)
{
    bind_virtual_functions(
        default_Shape_area);

    me->origin = origin;
}

Void Shape_reset(_Shape me)
{
    me->origin.x = 0;
    me->origin.y = 0;
    CObject_reset((_CObject) me);
}
