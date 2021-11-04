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
        (Implemented, (void, rotate, ()))),
    Funs(
        (Override, (float, area, ())),
        (Override, (void, draw, ()))));

PoolSize(10);

extern Const(float, pi);

SetProp(uint32, radius);
GetProp(uint32, radius);

#undef Type
#undef Parent
#endif // CIRCLE_H
