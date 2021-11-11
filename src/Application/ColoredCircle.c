#include "ColoredCircle.h"
#include "Circle.h"
#include <stdio.h>

#undef Type
#define Type ColoredCircle

ClassSetup(
    Extends(Circle),
    NA,
    FunOverrideSetup(
        ((void, draw, NA), Shape),
        ((void, rotate, Params(uint8 const degrees)), Circle)));

SetterImpl(Color, color);
GetterImpl(Color, color);

Init
{
    CircleParams * circleParams = super_params;
    circleParams->origin = params.origin;
    circleParams->radius = params.radius;
    me->data.color = params.color;
}

Terminate {}

FunOverride(void, draw, NA)
{
    super_Shape_draw(Cast(Shape, me));
    super_Circle_draw(Cast(Circle, me));
    printf("ColoredCircle draw\n");
}

FunOverride(void, rotate, Params(uint8 const degrees))
{
    super_Circle_rotate(Cast(Circle, me), 30);
    printf("ColoredCircle rotate %d\n", degrees);
}
