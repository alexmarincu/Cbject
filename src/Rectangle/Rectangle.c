#include "RectangleSuper.h"

#define RECTANGLE_POOL_SIZE 10

struct Rectangle rectanglePool[RECTANGLE_POOL_SIZE];

static _UInt32 override_Shape_area(Rectangle me);
static _UInt8 override_CObject_objectSize(Rectangle me);

static _UInt8 override_CObject_objectSize(Rectangle me)
{
    return sizeof(*me);
}

Void Rectangle_init(_Rectangle me, RectangleInitParams Ref params)
{
    static RectangleVT const vT = {
        {{(_UInt8(Ref)(CObject me)) override_CObject_objectSize},
         (_UInt32(Ref)(Shape me)) override_Shape_area}};

    Shape_init((_Shape) me, (ShapeInitParams Ref) params);
    ((_CObject) me)->vT = (CObjectVT Ref) &vT;
    me->width = params->width;
    me->height = params->height;
}

__Rectangle get_Rectangle(RectangleInitParams Ref params)
{
    __Rectangle me = null;
    _UInt32 i;

    for (i = 0; i < RECTANGLE_POOL_SIZE; i++)
    {
        if (CObject_isInitialized((CObject) &rectanglePool[i]) == false)
        {
            me = &rectanglePool[i];
            Rectangle_init(me, params);
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

static _UInt32 override_Shape_area(Rectangle me) { return me->width * me->height; }
