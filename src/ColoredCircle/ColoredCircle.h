#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Circle/Circle.h"
#include "Color.h"

#define Class_ ColoredCircle

class_params(
    UInt32 const radius,
    Color const color);

setters_getters(
    (UInt32, radius),
    (Color, color));

#undef Class_
#endif // COLOREDCIRCLE_H
