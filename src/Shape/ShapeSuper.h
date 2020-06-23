#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CObject/CObjectSuper.h"
#include "Shape.h"

class_members(
    _Point origin);

class_virtual_functions(
    virtual_fun(_UInt32, area);
    virtual_fun(Void, draw));

_default_fun(_UInt32, area);
_default_fun(Void, draw);

#endif // SHAPESUPER_H
