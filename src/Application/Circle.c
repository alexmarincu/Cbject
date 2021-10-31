#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

ClassSetup(
    VirtFunCalls(
        (void, rotate, (void), (void))),
    BindFuns(
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

OverrideFun(void, draw, (void))
{
    Shape_s_draw(Cast(Shape, me));
    printf("Circle draw\n");
}

OverrideFun(float, area, (void)) { return me->d.radius * me->d.radius * Circle_pi; }
OverrideFun(void, rotate, (void)) { printf("Rotate clockwise\n"); }

#undef Parent
#undef Type
