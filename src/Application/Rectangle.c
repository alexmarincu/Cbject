#include "Rectangle.h"
#include "Shape.h"

#define Type Rectangle
#define Parent Shape

ClassSetup(
    (),
    BindFuns(
        (Shape, (float, area, ()))));

Init
{
    me->data.width = params.width;
    me->data.height = params.height;
    superParams->origin = params.origin;
}

Terminate {}

SetterCustom(uint32, width)
{
    me->data.width = width;
}

Setter(uint32, height);

Getter(uint32, width);
Getter(uint32, height);

Fun(void, makeSquare, Params(uint32 const edgeSize))
{
    me->data.height = edgeSize;
    me->data.width = edgeSize;
}

OverrideFun(float, area, ()) { return me->data.width * me->data.height; }

#undef Parent
#undef Type
