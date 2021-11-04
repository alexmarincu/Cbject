#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

ClassSetup(
    VirtFunCalls(
        (void, rotate, (), ())),
    BindFuns(
        (Shape, (float, area, ())),
        (Shape, (void, draw, ())),
        (Circle, (void, rotate, ()))));

Const(float, pi = 3.14);

Init
{
    me->data.radius = params.radius;
    superParams->origin = params.origin;
}

Terminate {}

DefaultSetProp(uint32, radius);
DefaultGetProp(uint32, radius);

OverrideFun(void, draw, ())
{
    super_Shape_draw(Cast(Shape, me));
    printf("Circle draw\n");
}

OverrideFun(float, area, ()) { return me->data.radius * me->data.radius * Circle_pi; }
OverrideFun(void, rotate, ()) { printf("Rotate clockwise\n"); }

#undef Parent
#undef Type
