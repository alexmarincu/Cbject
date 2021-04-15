#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Shape.h"

#define class Circle
#define superClass Shape

Class((uint32 const radius),
      (int32 radius));

PublicConstant(float, pi);
PublicConstants((float, anotherPi));

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
