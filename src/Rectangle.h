#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

#define klass Rectangle
#define superKlass Shape

Klass(
    Params(_,
        Point origin,
        uint32 width,
        uint32 height),
    Properties(_,
        uint32 width,
        uint32 height),
    VirtualFunctions(0));

Setters(_,
    (uint32, width),
    (uint32, height));

Getters(_,
    (uint32, width),
    (uint32, height));

Function(uint32, test, (_, uint32 const a));

#undef superKlass
#undef klass
#endif // RECTANGLE_H
