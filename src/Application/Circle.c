#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

PoolSize(10);

ClassSetup(
    VirtFunCalls(_, (void, rotate, (0), (0))),
    BindSuperFuns(_,
        (Shape, float, area, (0)),
        (Shape, void, draw, (0)),
        (Circle, void, rotate, (0))));

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

    me->props.radius = params->radius;
}

Terminate {}

DefaultSet(uint32, radius);
DefaultGet(uint32, radius);

SuperFun(void, draw, (0))
{
    s_Shape_draw((Shape *) me);
    printf("Circle draw\n");
}

SuperFun(float, area, (0)) { return me->props.radius * me->props.radius * Circle_pi; }
SuperFun(void, rotate, (0)) { printf("Rotate clockwise\n"); }

#undef Parent
#undef Type
