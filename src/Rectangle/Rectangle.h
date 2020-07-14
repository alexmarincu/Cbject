#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Shape.h"

#undef Class
#define Class Rectangle

class_init_params(
    Point const origin,
    UInt32 const width,
    UInt32 const height);

class_pool_size(10);

setters_getters(
    (UInt32, width),
    (UInt32, height));

fun(UInt32, test, (UInt32 const a));

#endif // RECTANGLE_H
