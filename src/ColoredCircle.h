#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

#define Cbj_Type ColoredCircle
#define Cbj_Parent Circle

Class(
    Params(_,
        Point origin,
        uint32 radius,
        Color color),
    Props(_, Color color),
    VirtFuns(0));

Setters(_,
    (uint32, radius),
    (Color, color));

Getters(_,
    (uint32, radius),
    (Color, color));

OverrideFuns(_,
    (void, draw, (_, uint8 const a)),
    (void, rotate, (0)));

#undef Cbj_Type
#undef Cbj_Parent
#endif // COLOREDCIRCLE_H
