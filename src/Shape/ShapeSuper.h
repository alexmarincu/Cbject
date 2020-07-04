#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CObject/CObjectSuper.h"
#include "Shape.h"

#undef class
#define class Shape
#undef super_class
#define super_class CObject

abstract_class_members(
    mPoint origin;);

class_virtual_functions(
    virtual_fun(mFloat, area);
    virtual_fun(Void, draw, UInt8 a););

super_fun(Void, draw, UInt8 a);

#endif // SHAPESUPER_H
