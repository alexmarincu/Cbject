#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Shape.h"

#undef class
#define class Rectangle
#undef super_class
#define super_class Shape

class_init_params(
    Point origin,
    UInt32 width,
    UInt32 height);

set_get(UInt32, width);
set_get(UInt32, height);
fun(_UInt32, test, UInt32 a);

#endif // RECTANGLE_H
