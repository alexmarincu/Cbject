#ifndef SUPERSHAPE_H
#define SUPERSHAPE_H
#include "Shape.h"

#define class Shape
#define superClass Object
//==>
abstractClassMembers(ShapeMembers);

virtualFunctions(
    (float, area, ()),
    (void, draw, (uint8 const a)));
//<==
#undef superClass
#undef class
#endif // SUPERSHAPE_H
