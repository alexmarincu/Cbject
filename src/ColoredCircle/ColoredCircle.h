#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Circle/Circle.h"
#include "Color.h"

#undef Class_
#define Class_ ColoredCircle

class_init_params(
    UInt32 const radius,
    Color const color);

setters_getters(
    (UInt32, radius),
    (Color, color));

#endif // COLOREDCIRCLE_H
