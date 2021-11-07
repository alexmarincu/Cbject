#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

ClassSetup(
    VirtFunSetup(
        ((void, rotate, NA), NA)),
    FunOverrideSetup(
        ((float, area, NA), Shape),
        ((void, draw, NA), Shape),
        ((void, rotate, NA), Circle)));

Const(float, pi) = 3.14;
Var(Point, point) = {.x = 5, .y = 6};

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
