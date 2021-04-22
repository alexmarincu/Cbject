#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Circle/Circle.h"
#include "Color.h"

#define klass ColoredCircle
#define superKlass Circle

Klass(
    InitParams(_,
               Point origin,
               uint32 radius,
               Color color),
    Members(_,
            Color color),
    VirtualFunctions(0));

Setters(
    (uint32, radius),
    (Color, color));

Getters(
    (uint32, radius),
    (Color, color));

#undef klass
#undef superKlass
#endif // COLOREDCIRCLE_H
