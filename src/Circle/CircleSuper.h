#ifndef CIRCLESUPER_H
#define CIRCLESUPER_H
#include "../Shape/ShapeSuper.h"
#include "Circle.h"

#undef class
#define class Circle
#undef super_class
#define super_class Shape

class_members(
    UInt32 radius);

#endif // CIRCLESUPER_H
