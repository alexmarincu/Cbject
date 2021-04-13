#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Shape.h"

#define class Circle
#define superClass Shape

PublicConstant(float, pi);
PublicConstants((float, anotherPi));



    #define CircleMembers \
uint32 radius
InitParams(
    uint32 const radius);
DeclareClass(CircleMembers);



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
