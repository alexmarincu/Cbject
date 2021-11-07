#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

#define Type Rectangle
#define Parent Shape

Class(
    Params(
        Point origin,
        uint32 width,
        uint32 height),
    Data(
        ((uint32, width), Public),
        ((uint32, height), Public)),
    NA,
    Funs(
        ((void, makeSquare, Params(uint32 const edgeSize)), Final),
        ((float, area, NA), Override)));

PoolSize(10);

#undef Parent
#undef Type
#endif // RECTANGLE_H
