#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

ClassSetup(
    VirtFunCalls(
        (void, rotate, NA, NA)),
    FunOverrides(
        (Shape, (float, area, NA)),
        (Shape, (void, draw, NA)),
        (Circle, (void, rotate, NA))));

Const(float, pi = 3.14);

Init
{
    me->data.radius = params.radius;
    superParams->origin = params.origin;
}

Terminate {}

SetImpl(uint32, radius);
GetImpl(uint32, radius);

FunOverride(void, draw, NA)
{
    super_Shape_draw(Cast(Shape, me));
    printf("Circle draw\n");
}

FunOverride(float, area, NA) { return me->data.radius * me->data.radius * Circle_pi; }
FunOverride(void, rotate, NA) { printf("Rotate clockwise\n"); }

#undef Parent
#undef Type
