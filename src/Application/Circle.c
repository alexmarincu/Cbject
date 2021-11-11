#include "Circle.h"
#include <stdio.h>

#undef Type
#define Type Circle

ClassSetup(
    Extends(Shape),
    VirtFunSetup(
        ((void, rotate, Params(UInt8 const degrees)), Params(degrees))),
    FunOverrideSetup(
        ((float, area, NA), Shape),
        ((void, draw, NA), Shape),
        ((void, rotate, Params(UInt8 const degrees)), Circle)));

Const(float, pi) = 3.14;
Var(Point, point) = {.x = 5, .y = 6};

Init
{
    ShapeParams * shapeParams = super_params;
    shapeParams->origin = params.origin;
    me->data.radius = params.radius;
}

Terminate {}

SetterImpl(UInt32, radius);
GetterImpl(UInt32, radius);

FunOverride(void, draw, NA)
{
    super_Shape_draw(Cast(Shape, me));
    printf("Circle draw\n");
}

FunOverride(float, area, NA) { return me->data.radius * me->data.radius * Circle_pi; }
FunOverride(void, rotate, Params(UInt8 const degrees)) { printf("Circle rotate %d\n", degrees); }
