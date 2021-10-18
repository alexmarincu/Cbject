#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

PoolSize(10);

ClassSetup(
    VirtFunCalls(, (void, rotate, (0), (0))),
    BindSuperFuns(,
        (Shape, float, area, (0)),
        (Shape, void, draw, (0)),
        (Circle, void, rotate, (0))));

Consts(,
    (float, pi = 3.14),
    (float, anotherPi = 3.14));

PrivateConsts(,
    (float, privatePi = 3.14),
    (float, anotherPrivatePi = 3.14));

Init
{
    *super_params = (ShapeParams){
        .origin.x = params->origin.x,
        .origin.y = params->origin.y};

    me->props.radius = params->radius;
}

DefaultSetProp(uint32, radius);
DefaultGetProp(uint32, radius);

SuperFun(void, draw, (0))
{
    super_Shape_draw((Shape *) me);
    printf("Circle draw\n");
}

SuperFun(float, area, (0)) { return me->props.radius * me->props.radius * Circle_pi; }
SuperFun(void, rotate, (0)) { printf("Rotate clockwise\n"); }

#undef Parent
#undef Type
