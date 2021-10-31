#include "Rectangle.h"
#include "Shape.h"

#define Type Rectangle
#define Parent Shape

ClassSetup(
    (void),
    BindFuns(
        (Shape, float, area, (void))));

DefaultSetProp(uint32, width);
DefaultSetProp(uint32, height);

DefaultGetProp(uint32, width);
DefaultGetProp(uint32, height);

Init
{
    me->d.width = params.width;
    me->d.height = params.height;
    s_params->origin = params.origin;
    // Shape_init(Cast(me, Shape), (ShapeParams){params.origin.x, params.origin.y});
}

Terminate {}

Fun(uint32, test, Params(uint32 const ab)) { return ab; }
OverrideFun(float, area, (void)) { return me->d.width * me->d.height; }

#undef Parent
#undef Type
