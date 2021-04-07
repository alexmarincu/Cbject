#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Circle/Circle.h"
#include "Color.h"

#define class ColoredCircle
//==>
classParams(
    uint32 const radius,
    Color const color);

settersGetters(
    (uint32, radius),
    (Color, color));
//<==
#undef class
#endif // COLOREDCIRCLE_H
