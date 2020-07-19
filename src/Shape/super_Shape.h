#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CO/super_CO.h"
#include "Shape.h"

#undef Class_
#define Class_ Shape
#undef super_Class_
#define super_Class_ CO

virtual_class_members(
    Point origin);

virtual_functions(
    (Float, area, ()),
    (Void, draw, (UInt8 const a)));

#endif // SHAPESUPER_H
