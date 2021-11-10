#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"

#undef Type
#define Type Shape

AbstractClass(
    NA,
    Params(
        Point origin),
    Data(
        ((Point, origin), Public)),
    VirtFuns(
        ((float, area, NA), Pure),
        ((void, draw, NA), Impl)),
    NA);

#endif // SHAPE_H
