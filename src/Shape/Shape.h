#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"
#include "../Cbject/Cbject.h"

#define class Shape
#define superClass Cbject

InitParams(Point origin);
Members(Point origin);
DeclareAbstractClass();
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
