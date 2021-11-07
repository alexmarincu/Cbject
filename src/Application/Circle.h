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
        ((uint32, radius), Public)),
    VirtFuns(
        ((void, rotate, NA), Impl)),
    Funs(
        ((float, area, NA), Override),
        ((void, draw, NA), Override)));

PoolSize(10);

extern Const(float, pi);

#undef Type
#undef Parent
#endif // CIRCLE_H
