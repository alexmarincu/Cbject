#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

ClassSetup(
    VirtFunCalls(
        (void, rotate, ParamsNone, ParamsNone)),
    BindFuns(
        (Shape, (float, area, ParamsNone)),
        (Shape, (void, draw, ParamsNone)),
        (Circle, (void, rotate, ParamsNone))));

Const(float, pi = 3.14);

Init
{
    me->d.radius = p.radius;
    sp->origin = p.origin;
}

Terminate {}

DefaultSetProp(uint32, radius);
DefaultGetProp(uint32, radius);

OverrideFun(void, draw, ParamsNone)
{
    Shape_s_draw(Cast(Shape, me));
    printf("Circle draw\n");
}

OverrideFun(float, area, ParamsNone) { return me->d.radius * me->d.radius * Circle_pi; }
OverrideFun(void, rotate, ParamsNone) { printf("Rotate clockwise\n"); }

#undef Parent
#undef Type
