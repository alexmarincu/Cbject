#ifndef CIRCLESUPER_H
#define CIRCLESUPER_H
#include "../Shape/super_Shape.h"
#include "Circle.h"

#undef Class_
#define Class_ Circle
#undef super_Class_
#define super_Class_ Shape

virtual_class_members(
    UInt32 radius);

virtual_functions((Void, rotate, ()));

#endif // CIRCLESUPER_H
