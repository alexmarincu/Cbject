#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Cbject/Cbject.h"
#include "Circle.h"
#include "Color.h"
typedefClass_(ColoredCircle);
struct ColoredCircleClass {
    extends_(CircleClass);
};
struct ColoredCircle {
    extends_(Circle);
    Color color;
};
ColoredCircleClass const * ColoredCircleClass_instance(void);
ColoredCircle * ColoredCircle_init(
    ColoredCircle * const coloredCircle,
    Point const origin,
    uint32_t const radius,
    Color const color
);
#endif // COLOREDCIRCLE_H
