#include "Rectangle.h"
#include "Shape.h"

#define Type Rectangle
#define Parent Shape
PoolSize(10);

ClassSetup(
    VirtFunCalls(0),
    BindFuns(_, (float, Shape, area, (0))));

DefaultSetters(_,
    (uint32, width),
    (uint32, height));

DefaultGetters(_,
    (uint32, width),
    (uint32, height));

Init
{
    *s_params = (ShapeParams){
        .origin.x = params->origin.x,
        .origin.y = params->origin.y};

    me->p.width = params->width;
    me->p.height = params->height;
}

Terminate {}
Fun(uint32, test, (_, uint32 const a)) { return a; }
SuperFun(float, area, (0)) { return me->p.width * me->p.height; }

#undef Parent
#undef Type
