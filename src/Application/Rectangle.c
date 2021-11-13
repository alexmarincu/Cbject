#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"

#undef Type
#define Type Rectangle

ClassSetup(
    Extends(Shape),
    NA,
    FunOverrideSetup(
        ((float, area, NA), Shape)));

Init
{
    Shape_init(Cast(me, Shape), &(ShapeParams){params->origin});
    me->data.width = params->width;
    me->data.height = params->height;
}

Terminate {}

Setter(uint32, width) { me->data.width = width; }
SetterImpl(uint32, height);
GetterImpl(uint32, width);
GetterImpl(uint32, height);

Fun(void, makeSquare, Params(uint32 const edgeSize))
{
    me->data.height = edgeSize;
    me->data.width = edgeSize;
}

FunOverride(float, area, NA) { return me->data.width * me->data.height; }
