#include "Rectangle.h"
#include "Shape.h"

#undef Type
#define Type Rectangle

ClassSetup(
    Shape,
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

Set(uint32, width) { me->data.width = width; }
SetImpl(uint32, height);
GetImpl(uint32, width);
GetImpl(uint32, height);

Fun(void, makeSquare, Params(uint32 const edgeSize))
{
    me->data.height = edgeSize;
    me->data.width = edgeSize;
}

FunOverride(float, area, NA) { return me->data.width * me->data.height; }
