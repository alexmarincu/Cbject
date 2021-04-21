#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Shape.h"

#define class Rectangle
#define superClass Shape

Class(
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

Function(uint32, test, (uint32 const a));

#undef superClass
#undef class
#endif // RECTANGLE_H
