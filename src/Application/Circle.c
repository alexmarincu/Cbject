#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

PoolSize(10);

ClassSetup(
    VirtFunCalls(_, (void, rotate, (0), (0))),
    BindFuns(_,
        (float, Shape, area, (0)),
        (void, Shape, draw, (_, uint8 const a)),
        (void, Circle, rotate, (0))));

Consts(_,
    (float, pi = 3.14),
    (float, anotherPi = 3.14));

PrivateConsts(_,
    (float, privatePi = 3.14),
    (float, anotherPrivatePi = 3.14));

Init
{
    *s_params = (ShapeParams){
        .origin.x = params->origin.x,
        .origin.y = params->origin.y};

    me->p.radius = params->radius;
}

Terminate {}

DefaultSet(uint32, radius);
DefaultGet(uint32, radius);

SuperFun(void, draw, (_, uint8 const a))
{
    s_Shape_draw((Shape *) me, a);
    printf("Circle draw\n");
}

SuperFun(float, area, (0)) { return me->p.radius * me->p.radius * Circle_pi; }
SuperFun(void, rotate, (0)) { printf("Rotate clockwise\n"); }

#undef Parent
#undef Type
