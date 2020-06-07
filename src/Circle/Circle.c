#include "CircleSuper.h"

#define CIRCLE_POOL_SIZE 10

// Data
struct Circle circlePool[CIRCLE_POOL_SIZE];

static _UInt32 override_Shape_area(Circle me);
static _UInt8 override_CObject_objectSize(Circle me);

static _UInt8 override_CObject_objectSize(Circle me)
{
    return sizeof(*me);
}

Void Circle_init(_Circle me, CircleInitParams Ref params)
{
    static CircleVT const vT = {
        {{(_UInt8(Ref)(CObject me)) override_CObject_objectSize},
         (_UInt32(Ref)(Shape me)) override_Shape_area}};

    Shape_init((_Shape) me, (ShapeInitParams Ref) params);
    ((_CObject) me)->vT = (CObjectVT Ref) &vT;
    me->radius = params->radius;
}

__Circle get_Circle(CircleInitParams Ref params)
{
    __Circle me = null;
    _UInt32 i;

    for (i = 0; i < CIRCLE_POOL_SIZE; i++)
    {
        if (CObject_isInitialized((CObject) &circlePool[i]) == false)
        {
            me = &circlePool[i];
            Circle_init(me, params);
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
    me->radius = 0;
    Shape_reset((_Shape) me);
}

static _UInt32 override_Shape_area(Circle me) { return me->radius * me->radius * 3; }
