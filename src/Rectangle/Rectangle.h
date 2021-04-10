#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Shape.h"

#define class Rectangle
#define superClass Shape

classParams(
    Point const origin,
    uint32 const width,
    uint32 const height);

#define RectangleMembers \
uint32 width, \
uint32 height

classDeclaration(RectangleMembers);

settersGetters(
    (uint32, width),
    (uint32, height));

function(uint32, test, (uint32 const a));

#undef superClass
#undef class
#endif // RECTANGLE_H
