#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CObject/CObjectSuper.h"
#include "Shape.h"

#undef class
#define class Shape
#undef super_class
#define super_class CObject

abstract_class_members(
    mPoint origin);

virtual_functions(
    (mFloat, area, ()),
    (Void, draw, (UInt8 a)));

#endif // SHAPESUPER_H
