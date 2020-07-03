#ifndef RECTANGLESUPER_H
#define RECTANGLESUPER_H
#include "../Shape/ShapeSuper.h"
#include "Rectangle.h"

#undef class
#define class Rectangle
#undef super_class
#define super_class Shape

class_members(
    mUInt32 width;
    mUInt32 height;);

class_virtual_functions();

#endif // RECTANGLESUPER_H
