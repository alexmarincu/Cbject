#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CO/super_CO.h"
#include "Shape.h"

#define Class_ Shape
#define super_Class_ CO

virtual_class_members(
    Point origin);

virtual_functions(
    (Float, area, ()),
    (Void, draw, (UInt8 const a)));

#undef super_Class_
#undef Class_

#endif // SHAPESUPER_H
