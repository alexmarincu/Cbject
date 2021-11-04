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
        uint32 width,
        uint32 height),
    VirtFuns(
        (final, (uint32, test, Params(uint32 const ab))),
        (override, (float, area, ()))));

PoolSize(10);

SetProp(uint32, width);
SetProp(uint32, height);

GetProp(uint32, width);
GetProp(uint32, height);

#undef Parent
#undef Type
#endif // RECTANGLE_H
