#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CObject/CObjectSuper.h"
#include "Shape.h"

#undef class
#define class Shape
#undef super_class
#define super_class CObject

abstract_class_members(
    Point origin);

virtual_functions(
    (Float, area, ()),
    (Void, draw, (UInt8 const a)));

#endif // SHAPESUPER_H
