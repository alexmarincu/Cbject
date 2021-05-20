#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

#define Type ColoredCircle
#define Parent Circle

Class(
    Params(_,
        Point origin,
        uint32 radius,
        Color color),
    Props(_, Color color),
    VirtFuns(0));

SetProps(_,
    (uint32, radius),
    (Color, color));

GetProps(_,
    (uint32, radius),
    (Color, color));

SuperFuns(_,
    (void, draw, (0)),
    (void, rotate, (0)));

#undef Type
#undef Parent
#endif // COLOREDCIRCLE_H
