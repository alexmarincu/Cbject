#include "Rectangle.h"
#include "Shape.h"

#define Type Rectangle
#define Parent Shape

ClassSetup(
    (),
    BindFuns(
        (Shape, (float, area, ()))));

DefaultSetProp(uint32, width);
DefaultSetProp(uint32, height);

DefaultGetProp(uint32, width);
DefaultGetProp(uint32, height);

Init
{
    me->d.width = p.width;
    me->d.height = p.height;
    sp->origin = p.origin;
}

Terminate {}

Fun(uint32, test, Params(uint32 const ab)) { return ab; }
OverrideFun(float, area, ()) { return me->d.width * me->d.height; }

#undef Parent
#undef Type
