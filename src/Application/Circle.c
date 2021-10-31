#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

ClassSetup(
    VirtFunCalls(
        (void, rotate, (void), (void))),
    BindSuperFuns(
        (Shape, float, area, (void)),
        (Shape, void, draw, (void)),
        (Circle, void, rotate, (void))));

Const(float, pi = 3.14);
static Const(float, privatePi = 3.14);

Init
{
    me->d.radius = params.radius;
    s_params->origin = params.origin;
    // Shape_init(Cast(me, Shape), (ShapeParams){params.origin.x, params.origin.y});
}

Terminate {}

DefaultSetProp(uint32, radius);
DefaultGetProp(uint32, radius);

SuperFun(void, draw, (void))
{
    super_Shape_draw(Cast(Shape, me));
    printf("Circle draw\n");
}

SuperFun(float, area, (void)) { return me->d.radius * me->d.radius * Circle_pi; }
SuperFun(void, rotate, (void)) { printf("Rotate clockwise\n"); }

#undef Parent
#undef Type
