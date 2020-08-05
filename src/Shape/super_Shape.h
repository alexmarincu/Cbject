#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CObject/Obj/super_Obj.h"
#include "Shape.h"

#define Class_ Shape
#define super_Class_ Obj

virtual_class_members(Point origin);

virtual_functions(
    (Float, area, ()),
    (Void, draw, (UInt8 const a)));

#undef super_Class_
#undef Class_
#endif // SHAPESUPER_H
