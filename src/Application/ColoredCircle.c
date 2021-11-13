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
    Circle_init(Cast(me, Circle), &(CircleParams){params->origin, params->radius});
    me->data.color = params->color;
}

Terminate {}

FunOverride(void, draw, NA)
{
    superShape_draw(Cast(me, Shape));
    superCircle_draw(Cast(me, Circle));
    printf("ColoredCircle draw\n");
}

FunOverride(void, rotate, Params(uint8 const degrees))
{
    superCircle_rotate(Cast(me, Circle), 30);
    printf("ColoredCircle rotate %d\n", degrees);
}
