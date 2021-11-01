#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

#define Type Circle
#define Parent Shape

Class(
    Params(
        Point origin,
        uint32 radius),
    Data(
        int32 radius),
    VirtFuns(
        (void, rotate, ())));

PoolSize(10);

extern Const(float, pi);

SetProp(uint32, radius);
GetProp(uint32, radius);

OverrideFun(float, area, ());
OverrideFun(void, draw, ());
OverrideFun(void, rotate, ());

#undef Type
#undef Parent
#endif // CIRCLE_H
