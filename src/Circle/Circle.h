#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Shape.h"

#undef class
#undef super_class
#define class Circle
#define super_class Shape
#define Circle_poolSize 10U

class_init_params(
    Point origin;
    UInt32 radius);

set_get(UInt32, radius);

#endif // CIRCLE_H
