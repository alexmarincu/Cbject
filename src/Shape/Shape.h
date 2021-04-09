#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"
#include "../CObject/Object/Object.h"

#define class Shape
#define superClass Object
//==>
abstractClassParams(Point origin);

#define ShapeMembers \
Point origin

classDeclaration(ShapeMembers);

setterGetter(Point, origin);

functions(
    (float, area, ()),
    (void, draw, (uint8 const a)));
//<==
#undef superClass
#undef class
#endif // SHAPE_H
