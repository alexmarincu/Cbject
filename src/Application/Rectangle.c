#include "Rectangle.h"
#include "Shape.h"

#define Type Rectangle
#define Parent Shape
PoolSize(10);

ClassSetup(
    VirtFunCalls(0),
    BindSuperFuns(_,
        (Shape, float, area, (0))));

DefaultSetProps(_,
    (uint32, width),
    (uint32, height));

DefaultGetProps(_,
    (uint32, width),
    (uint32, height));

Init
{
    *super_params = (ShapeParams){
        .origin.x = params->origin.x,
        .origin.y = params->origin.y};

    me->props.width = params->width;
    me->props.height = params->height;
}

Fun(uint32, test, (_, uint32 const ab)) { return ab; }
SuperFun(float, area, (0)) { return me->props.width * me->props.height; }

#undef Parent
#undef Type
