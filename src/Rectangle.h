#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

#define Cbj_Type Rectangle
#define Cbj_Parent Shape

Class(
    Params(_,
        Point origin,
        uint32 width,
        uint32 height),
    Props(_,
        uint32 width,
        uint32 height),
    VirtFuns(0));

Setters(_,
    (uint32, width),
    (uint32, height));

Getters(_,
    (uint32, width),
    (uint32, height));

Fun(uint32, test, (_, uint32 const a));
OverrideFun(float, area, (0));

#undef Cbj_Parent
#undef Cbj_Type
#endif // RECTANGLE_H
