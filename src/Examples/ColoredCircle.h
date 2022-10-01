#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Cbject/Cbject.h"
#include "Circle.h"
#include "Color.h"
typedef struct ColoredCircle_Class ColoredCircle_Class;
typedef struct ColoredCircle ColoredCircle;
struct ColoredCircle_Class {
    extends_(Circle_Class);
};
struct ColoredCircle {
    extends_(Circle);
    Color color;
};
ColoredCircle_Class const * ColoredCircle_Class_(void);
ColoredCircle * ColoredCircle_init(
    ColoredCircle * const me,
    Point const origin,
    uint32_t const radius,
    Color const color
);
#endif // COLOREDCIRCLE_H
