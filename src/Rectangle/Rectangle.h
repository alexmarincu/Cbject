#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Point.h"

#define Class_ Rectangle

class_init_params(
    Point const origin,
    UInt32 const width,
    UInt32 const height);

setters_getters(
    (UInt32, width),
    (UInt32, height));

fun(UInt32, test, (UInt32 const a));

#undef Class_

#endif // RECTANGLE_H
