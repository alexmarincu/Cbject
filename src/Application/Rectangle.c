#include "Rectangle.h"
#include "Shape.h"

#define Type Rectangle
#define Parent Shape

ClassSetup(
    (),
    FunOverrides(
        (Shape, (float, area, ()))));

Init
{
    me->data.width = params.width;
    me->data.height = params.height;
    superParams->origin = params.origin;
}

Terminate {}

Set(uint32, width)
{
    me->data.width = width;
}

SetImpl(uint32, height);

GetImpl(uint32, width);
GetImpl(uint32, height);

Fun(void, makeSquare, Params(uint32 const edgeSize))
{
    me->data.height = edgeSize;
    me->data.width = edgeSize;
}

FunOverride(float, area, ()) { return me->data.width * me->data.height; }

#undef Parent
#undef Type
