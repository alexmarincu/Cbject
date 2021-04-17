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

#define x(...) int a(int s, ##__VA_ARGS__, int b, int c)

x();

#undef superClass
#undef class
#endif // SHAPE_H
