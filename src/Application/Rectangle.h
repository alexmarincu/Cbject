#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

#define Type Rectangle
#define Parent Shape

Class(
    Params(,
        Point origin,
        uint32 width,
        uint32 height),
    Props(,
        uint32 width,
        uint32 height),
    VirtFuns(0));

SetProps(,
    (uint32, width),
    (uint32, height));

GetProps(,
    (uint32, width),
    (uint32, height));

Fun(uint32, test, (, uint32 const ab));
SuperFun(float, area, (0));

#undef Parent
#undef Type
#endif // RECTANGLE_H
