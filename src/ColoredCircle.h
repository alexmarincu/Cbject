#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

#define CbjectType ColoredCircle
#define parent Circle

Class(
    Params(_,
        Point origin,
        uint32 radius,
        Color color),
    Props(_, Color color),
    VirtualFuns(0));

Setters(_,
    (uint32, radius),
    (Color, color));

Getters(_,
    (uint32, radius),
    (Color, color));

OverrideFuns(_,
    (void, draw, (_, uint8 const a)),
    (void, rotate, (0)));

#undef CbjectType
#undef parent
#endif // COLOREDCIRCLE_H
