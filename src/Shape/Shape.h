#ifndef SHAPE_H
#define SHAPE_H
#include "../CO/CO.h"
#include "Point.h"

#undef Class_
#define Class_ Shape

abstract_class_init_params(
    Point const origin);

set_get(Point, origin);

functions(
    (Float, area, ()),
    (Void, draw, (UInt8 const a)));

#endif // SHAPE_H
