#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

#define Type Circle
#define Parent Shape

Class(
    Params(,
        Point origin,
        uint32 radius),
    Data(,
        int32 radius),
    VirtFuns(,
        (void, rotate, (0))));

PoolSize(10);

extern Const(float, pi);

SetProp(uint32, radius);
GetProp(uint32, radius);

SuperFun(float, area, (0));
SuperFun(void, draw, (0));
SuperFun(void, rotate, (0));

#undef Type
#undef Parent
#endif // CIRCLE_H
