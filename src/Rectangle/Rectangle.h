#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Shape.h"

#undef class
#undef super_class
#define class Rectangle
#define super_class Shape
#define Rectangle_poolSize 10U

class_init_params(
    Point origin;
    UInt32 width;
    UInt32 height);

set_get(UInt32, width);
set_get(UInt32, height);
fun(mUInt32, test, UInt32 a);

#endif // RECTANGLE_H
