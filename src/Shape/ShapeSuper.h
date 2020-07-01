#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CObject/CObjectSuper.h"
#include "Shape.h"

class_members(
    mPoint origin);

class_virtual_functions(
    virtual_function(mUInt32, area);
    virtual_function(Void, draw, UInt8 a));

virtual_fun(mUInt32, area);
virtual_fun(Void, draw, UInt8 a);

#endif // SHAPESUPER_H
