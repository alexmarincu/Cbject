#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Shape.h"

#define class Rectangle
#define superClass Shape

#define RectangleMembers \
uint32 width, \
uint32 height

DeclareClass(RectangleMembers);

ClassInitParams(
    uint32 const width,
    uint32 const height);

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
