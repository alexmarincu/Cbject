#ifndef SUPER_CIRCLE_H
#define SUPER_CIRCLE_H
#include "../Shape/super_Shape.h"
#include "Circle.h"

#define Class_ Circle
#define super_Class_ Shape

virtual_class_members(
    UInt32 radius);

virtual_functions((Void, rotate, ()));

override_functions(
    (Float, Shape, area, ()),
    (Void, Shape, draw, (UInt8 const a)));

#undef super_Class_
#undef Class_

#endif // SUPER_CIRCLE_H
