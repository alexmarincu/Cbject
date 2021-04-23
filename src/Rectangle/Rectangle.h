#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Shape.h"

#define klass Rectangle
#define superKlass Shape

Klass(
    InitParams(_,
        Point origin,
        uint32 width,
        uint32 height),
    Members(_,
        uint32 width,
        uint32 height),
    VirtualFunctions(0));

Setters(
    (uint32, width),
    (uint32, height));

Getters(
    (uint32, width),
    (uint32, height));

Function(uint32, test, (_, uint32 const a));

#undef superKlass
#undef klass
#endif // RECTANGLE_H
