#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

#define klass ColoredCircle
#define superKlass Circle

Klass(
    InitParams(_,
        Point origin,
        uint32 radius,
        Color color),
    Properties(_, Color color),
    VirtualFunctions(0));

Setters(_,
    (uint32, radius),
    (Color, color));

Getters(_,
    (uint32, radius),
    (Color, color));

#undef klass
#undef superKlass
#endif // COLOREDCIRCLE_H
