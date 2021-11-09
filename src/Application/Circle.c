#include "Circle.h"
#include <stdio.h>

#undef Type
#define Type Circle

ClassSetup(
    Shape,
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
    ShapeParams * shapeParams = super_params;
    shapeParams->origin = params.origin;
    me->data.radius = params.radius;
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
