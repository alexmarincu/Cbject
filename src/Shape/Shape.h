#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"

#define class Shape
#define superClass Cbject

AbstractClass(
    InitParams(Point origin),
    Members(Point origin),
    VirtualFunctions(
        (float, area, ()),
        (void, draw, (uint8 const a))));

Setters((Point, origin));
Getters((Point, origin));

#undef superClass
#undef class
#endif // SHAPE_H
