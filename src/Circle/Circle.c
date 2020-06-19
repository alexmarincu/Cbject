#include "CircleSuper.h"

#define CIRCLE_POOL_SIZE 10

// Data
struct Circle circlePool[CIRCLE_POOL_SIZE];

default_set(UInt32, radius);
default_get(UInt32, radius);

override_fun(_UInt32, Shape, area);

class_init(Point origin, UInt32 radius)
{
    super_class_init(origin);
    
    bind_virtual_functions(
        override_virtual_fun(_UInt32, Shape, area));
    
    me->radius = radius;
}

__Circle Circle_get(Point origin, UInt32 radius)
{
    __Circle me = null;
    _UInt32 i;

    for (i = 0; i < CIRCLE_POOL_SIZE; i++)
    {
        if (CObject_isInitialized((CObject) &circlePool[i]) == false)
        {
            me = &circlePool[i];
            Circle_init(me, origin, radius);
            break;
        }
    }

    return me;
}

Void drop_Circle(__Circle me)
{
    Circle_reset(me);
    me = null;
}

Void Circle_reset(_Circle me)
{
    ((_Circle) me)->radius = 0;
    Shape_reset((_Shape) me);
}

static _UInt32 override_Shape_area(Circle me) { return me->radius * me->radius * 3; }