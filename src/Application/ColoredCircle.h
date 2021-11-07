#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

#define Type ColoredCircle
#define Parent Circle

Class(
    Params(
        Point origin,
        uint32 radius,
        Color color),
    Data(
        ((Color, color), Public)),
    NA,
    Funs(
        ((void, draw, NA), Override),
        ((void, rotate, NA), Override)));

PoolSize(10);

#undef Type
#undef Parent
#endif // COLOREDCIRCLE_H
