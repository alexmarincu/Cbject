#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

ClassSetup(
    VirtFunCalls(
        (void, rotate, (), ())),
    FunOverrides(
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

SetImpl(uint32, radius);
GetImpl(uint32, radius);

FunOverride(void, draw, ())
{
    super_Shape_draw(Cast(Shape, me));
    printf("Circle draw\n");
}

FunOverride(float, area, ()) { return me->data.radius * me->data.radius * Circle_pi; }
FunOverride(void, rotate, ()) { printf("Rotate clockwise\n"); }

#undef Parent
#undef Type
