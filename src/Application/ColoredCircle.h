#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

#undef Type
#define Type ColoredCircle

Class(
    Extends(Circle),
    Params(
        Point origin,
        UInt32 radius,
        Color color),
    Data(
        ((Color, color), Public)),
    NA,
    Funs(
        ((void, draw, NA), Override),
        ((void, rotate, Params(UInt8 const degrees)), Override)));

PoolSize(10);

#endif // COLOREDCIRCLE_H
