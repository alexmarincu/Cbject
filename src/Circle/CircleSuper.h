#ifndef CIRCLESUPER_H
#define CIRCLESUPER_H
#include "../Shape/ShapeSuper.h"
#include "Circle.h"

#undef class
#define class Circle
#undef super_class
#define super_class Shape

class_members(
    mUInt32 radius;);

class_virtual_functions();

#endif // CIRCLESUPER_H
