#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Shape.h"

#define class Rectangle
#define superClass Shape

Members(
    uint32 width, 
uint32 height);
#define RectangleMembe \
uint32 width, \
uint32 height

InitParams(
    uint32 const width,
    uint32 const height);

DeclareClass();



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
