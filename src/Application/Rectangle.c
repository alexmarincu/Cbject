#include "Rectangle.h"
#include "Shape.h"

#define Type Rectangle
#define Parent Shape

ClassSetup(
    (0),
    BindSuperFuns(
        (Shape, float, area, (0))));

DefaultSetProp(uint32, width);
DefaultSetProp(uint32, height);

DefaultGetProp(uint32, width);
DefaultGetProp(uint32, height);

Init
{
    me->d.width = params.width;
    me->d.height = params.height;
    s_params->origin = params.origin;
    // Shape_init(Cbject_cast(me, Shape), (ShapeParams){params.origin.x, params.origin.y});
}

Terminate {}

Fun(uint32, test, Params(uint32 const ab)) { return ab; }
SuperFun(float, area, (0)) { return me->d.width * me->d.height; }

#undef Parent
#undef Type
