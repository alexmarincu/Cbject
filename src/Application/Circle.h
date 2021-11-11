#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

#undef Type
#define Type Circle

Class(
    Extends(Shape),
    Params(
        Point origin,
        UInt32 radius),
    Data(
        ((UInt32, radius), Public)),
    VirtFuns(
        ((void, rotate, Params(UInt8 const degrees)), Impl)),
    Funs(
        ((float, area, NA), Override),
        ((void, draw, NA), Override)));

PoolSize(10);

extern Const(float, pi);

#endif // CIRCLE_H
