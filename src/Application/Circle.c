#include "Circle.h"
#include <stdio.h>

#undef Type
#define Type Circle

ClassSetup(
    Extends(Shape),
    VirtFunSetup(
        ((void, rotate, Params(uint8 const degrees)), Params(degrees))),
    FunOverrideSetup(
        ((float, area, NA), Shape),
        ((void, draw, NA), Shape),
        ((void, rotate, Params(uint8 const degrees)), Circle)));

Const(float, pi) = 3.14;
Var(Point, point) = {.x = 5, .y = 6};

Init
{
    Shape_init(Cast(me, Shape), &(ShapeParams){params->origin});
    me->data.radius = params->radius;
}

Terminate {}

SetterImpl(uint32, radius);
GetterImpl(uint32, radius);

FunOverride(void, draw, NA)
{
    superShape_draw(Cast(me, Shape));
    printf("Circle draw\n");
}

FunOverride(float, area, NA) { return me->data.radius * me->data.radius * Circle_pi; }
FunOverride(void, rotate, Params(uint8 const degrees)) { printf("Circle rotate %d\n", degrees); }
