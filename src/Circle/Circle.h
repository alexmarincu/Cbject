#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Shape.h"

#define class Circle
#define superClass Shape

PublicConstant(float, pi);
PublicConstants((float, anotherPi));


Members(
    int32 radius);
    #define CircleMembe \
uint32 radius
InitParams(
    uint32 const radius);
DeclareClass();



// setterGetter(uint32, radius);
Setter(uint32, radius);
Getter(uint32, radius);

OverrideFunctions(
    (float, Shape, area, ()),
    (void, Shape, draw, (uint8 const a)));

VirtualFunctions((void, rotate, ()));

Functions((void, rotate, ()));

#undef class
#undef superClass
#endif // CIRCLE_H
