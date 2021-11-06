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
        ((Color, color), Access_ReadWrite)),
    (),
    Funs(
        ((void, draw, ()), FunType_Override),
        ((void, rotate, ()), FunType_Override)));

PoolSize(10);

#undef Type
#undef Parent
#endif // COLOREDCIRCLE_H
