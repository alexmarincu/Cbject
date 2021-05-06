#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

#define CbjectType Rectangle
#define parent Shape

Class(
    Params(_,
        Point origin,
        uint32 width,
        uint32 height),
    Props(_,
        uint32 width,
        uint32 height),
    VirtualFuns(0));

Setters(_,
    (uint32, width),
    (uint32, height));

Getters(_,
    (uint32, width),
    (uint32, height));

Fun(uint32, test, (_, uint32 const a));
OverrideFun(float, area, (0));

#undef parent
#undef CbjectType
#endif // RECTANGLE_H
