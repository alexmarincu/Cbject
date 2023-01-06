#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../cbject/cbject.h"
#include "Circle.h"
#include "Color.h"
cbject_typedefClass(ColoredCircle);
struct ColoredCircleClass {
    cbject_is(CircleClass);
};
struct ColoredCircle {
    cbject_is(Circle);
    Color color;
};
ColoredCircleClass const * ColoredCircleClass_getInstance(void);
ColoredCircle * ColoredCircle_init(
    ColoredCircle * const coloredCircle,
    Point const origin,
    uint32_t const radius,
    Color const color
);
#endif // COLOREDCIRCLE_H
