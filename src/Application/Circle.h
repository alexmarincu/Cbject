#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

#undef Type
#define Type Circle

Class(
    Shape,
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

#endif // CIRCLE_H
