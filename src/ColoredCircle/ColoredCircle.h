#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Circle/Circle.h"
#include "Color.h"

#undef class
#define class ColoredCircle

class_init_params(
    UInt32 radius;
    Color color;);

class_pool_size(10);

set_get(UInt32, radius);
set_get(Color, color);

#endif // COLOREDCIRCLE_H
