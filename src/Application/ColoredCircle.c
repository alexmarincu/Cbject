#include "ColoredCircle.h"
#include "Circle.h"
#include <stdio.h>

#define Type ColoredCircle
#define Parent Circle

ClassSetup(
    NA,
    FunOverrideSetup(
        ((void, draw, NA), Shape),
        ((void, rotate, NA), Circle)));

SetImpl(Color, color);
GetImpl(Color, color);

Init
{
    me->data.color = params.color;
    superParams->origin = params.origin;
    superParams->radius = params.radius;
}

Terminate {}

FunOverride(void, draw, NA)
{
    super_Shape_draw(Cast(Shape, me));
    super_Circle_draw(Cast(Circle, me));
    printf("ColoredCircle draw\n");
}

FunOverride(void, rotate, NA)
{
    super_Circle_rotate(Cast(Circle, me));
    printf("Rotate counter-clockwise\n");
}

#undef Parent
#undef Type
