#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Shape.h"

#undef class
#define class Rectangle

class_init_params(
    Point origin;
    UInt32 width;
    UInt32 height;);

class_pool_size(10);

set_get(UInt32, width);
set_get(UInt32, height);
fun(mUInt32, test, (UInt32 a));

#endif // RECTANGLE_H
