#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

#define Type ColoredCircle
#define Parent Circle

Class(
    Params(,
        Point origin,
        uint32 radius,
        Color color),
    Props(, Color color),
    VirtFuns(0));

SetProps(,
    (uint32, radius),
    (Color, color));

GetProps(,
    (uint32, radius),
    (Color, color));

SuperFuns(,
    (void, draw, (0)),
    (void, rotate, (0)));

#undef Type
#undef Parent
#endif // COLOREDCIRCLE_H
