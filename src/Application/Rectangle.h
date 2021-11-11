#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

#undef Type
#define Type Rectangle

Class(
    Extends(Shape),
    Params(
        Point origin,
        UInt32 width,
        UInt32 height),
    Data(
        ((UInt32, width), Public),
        ((UInt32, height), Public)),
    NA,
    Funs(
        ((void, makeSquare, Params(UInt32 const edgeSize)), Final),
        ((float, area, NA), Override)));

PoolSize(10);

#endif // RECTANGLE_H
