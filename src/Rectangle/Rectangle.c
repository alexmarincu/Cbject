#include "RectangleSuper.h"

#define RECTANGLE_POOL_SIZE 10

default_set(UInt32, width);
default_get(UInt32, width);
default_set(UInt32, height);
default_get(UInt32, height);

fun(_UInt32, test, UInt32 a)
{
    return a;
}

override_fun(_UInt32, Shape, area);

class_init(Point origin, UInt32 width, UInt32 height)
{
    super_class_init(origin);

    bind_virtual_functions(
        override_virtual_fun(_UInt32, Shape, area));

    me->width = width;
    me->height = height;
}

struct Rectangle rectanglePool[RECTANGLE_POOL_SIZE];
__Rectangle Rectangle_get(Point origin, UInt32 width, UInt32 height)
{
    __Rectangle me = null;
    _UInt32 i;

    for (i = 0; i < RECTANGLE_POOL_SIZE; i++)
    {
        if (CObject_isInitialized((CObject) &rectanglePool[i]) == false)
        {
            me = &rectanglePool[i];
            Rectangle_init(me, origin, width, height);
            break;
        }
    }

    return me;
}

Void drop_Rectangle(__Rectangle me)
{
    Rectangle_reset(me);
    me = null;
}

Void Rectangle_reset(_Rectangle me)
{
    me->width = 0;
    me->height = 0;
    Shape_reset((_Shape) me);
}

override_fun(_UInt32, Shape, area) { return me->width * me->height; }
