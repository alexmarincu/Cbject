#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

#define Type ColoredCircle
#define Parent Circle

Class(
    Params(
        Point origin,
        uint32 radius,
        Color color),
    Data(
        Color color),
    VirtFuns(
        (override, (void, draw, ParamsNone)),
        (override, (void, rotate, ParamsNone))));

PoolSize(10);

SetProp(uint32, radius);
SetProp(Color, color);

GetProp(uint32, radius);
GetProp(Color, color);

#undef Type
#undef Parent
#endif // COLOREDCIRCLE_H
