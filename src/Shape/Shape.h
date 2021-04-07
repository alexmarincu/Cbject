#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"

#define class Shape
//==>
abstractClassParams(Point origin);
setterGetter(Point, origin);

functions(
    (float, area, ()),
    (void, draw, (uint8 const a)));
//<==
#undef class
#endif // SHAPE_H
