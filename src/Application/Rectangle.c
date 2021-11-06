#include "Rectangle.h"
#include "Shape.h"

#define Type Rectangle
#define Parent Shape

ClassSetup(
    (),
    BindFuns(
        (Shape, (float, area, ()))));

Setter(uint32, width);
Setter(uint32, height);

Getter(uint32, width);
Getter(uint32, height);

Init
{
    me->data.width = params.width;
    me->data.height = params.height;
    superParams->origin = params.origin;
}

Terminate {}

Fun(void, makeSquare, Params(uint32 const edgeSize))
{
    me->data.height = edgeSize;
    me->data.width = edgeSize;
}

OverrideFun(float, area, ()) { return me->data.width * me->data.height; }

#undef Parent
#undef Type
