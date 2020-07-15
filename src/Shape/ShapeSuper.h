#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CO/super_CO.h"
#include "Shape.h"

#undef Class
#define Class Shape
#undef SuperClass
#define SuperClass CO

abstract_class_members(
    Point origin);

virtual_functions(
    (Float, area, ()),
    (Void, draw, (UInt8 const a)));

#endif // SHAPESUPER_H
