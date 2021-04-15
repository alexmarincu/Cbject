#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"

#define class Shape
#define superClass Cbject

AbstractClass((Point origin),
              (Point origin));

Setters((Point, origin));
Getters((Point, origin));

Functions(
    (float, area, ()),
    (void, draw, (uint8 const a)));

VirtualFunctions(
    (float, area, ()),
    (void, draw, (uint8 const a)));

#undef superClass
#undef class
#endif // SHAPE_H
