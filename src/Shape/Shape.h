#ifndef SHAPE_H
#define SHAPE_H
#include "../CObject/CObject.h"
#include "Point.h"

#undef class
#define class Shape

abstract_class_init_params(
    Point origin);

set_get(Point, origin);

functions(
    (mFloat, area, ()),
    (Void, draw, (UInt8 a)));

#endif // SHAPE_H
