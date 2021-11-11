#include "Rectangle.h"
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
    ShapeParams * shapeParams = super_params;
    shapeParams->origin = params.origin;
    me->data.width = params.width;
    me->data.height = params.height;
}

Terminate {}

Setter(UInt32, width) { me->data.width = width; }
SetterImpl(UInt32, height);
GetterImpl(UInt32, width);
GetterImpl(UInt32, height);

Fun(void, makeSquare, Params(UInt32 const edgeSize))
{
    me->data.height = edgeSize;
    me->data.width = edgeSize;
}

FunOverride(float, area, NA) { return me->data.width * me->data.height; }
