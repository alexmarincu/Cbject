#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CObject/CObjectSuper.h"
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
