#ifndef SUPERCIRCLE_H
#define SUPERCIRCLE_H
#include "../Shape/superShape.h"
#include "Circle.h"

#define class Circle
#define superClass Shape
//==>
abstractClassMembers(CircleMembers);

virtualFunctions((void, rotate, ()));

overrideFunctions(
    (float, Shape, area, ()),
    (void, Shape, draw, (uint8 const a)));
//<==
#undef superClass
#undef class
#endif // SUPERCIRCLE_H
