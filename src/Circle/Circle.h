#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Shape.h"

#undef class
#define class Circle

class_init_params(
    Point origin,
    UInt32 radius);

class_pool_size(10);

set_get(UInt32, radius);

#endif // CIRCLE_H
