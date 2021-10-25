#include "Rectangle.h"
#include "Shape.h"

#define Type Rectangle
#define Parent Shape

ClassSetup(
    VirtFunCalls(0),
    BindSuperFuns(,
        (Shape, float, area, (0))));

DefaultSetProp(uint32, width);
DefaultSetProp(uint32, height);

DefaultGetProp(uint32, width);
DefaultGetProp(uint32, height);

Init
{
    *super_params = (ShapeParams){
        .origin.x = params->origin.x,
        .origin.y = params->origin.y};

    me->d.width = params->width;
    me->d.height = params->height;
}

Terminate {}

Fun(uint32, test, (, uint32 const ab)) { return ab; }
SuperFun(float, area, (0)) { return me->d.width * me->d.height; }

#undef Parent
#undef Type
