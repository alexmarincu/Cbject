#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Circle/Circle.h"
#include "Color.h"

#undef class
#undef super_class
#define class ColoredCircle
#define super_class Circle
#define ColoredCircle_poolSize 10U

class_init_params(
    UInt32 radius;
    Color color);

set_get(UInt32, radius);
set_get(Color, color);

#endif // COLOREDCIRCLE_H
