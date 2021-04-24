#ifndef SHAPE_H
#define SHAPE_H
#include "Cbject/Cbject.h"
#include "Point.h"

#define klass Shape
#define superKlass Cbject

AbstractKlass(
    InitParams(_, Point origin),
    Members(_, Point origin),
    VirtualFunctions(_,
        (float, area, (0)),
        (void, draw, (_, uint8 const a))));

Setters(_, (Point, origin));
Getters(_, (Point, origin));

#undef superKlass
#undef klass
#endif // SHAPE_H
