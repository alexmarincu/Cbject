#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

typedef struct ColoredCircle ColoredCircle;
typedef struct ColoredCircleClass ColoredCircleClass;

struct ColoredCircle {
    Circle circle;
    Color color;
};

struct ColoredCircleClass {
    CircleClass circleClass;
};

ColoredCircle * ColoredCircle_init(
    ColoredCircle * const coloredCircle,
    Point const origin,
    uint32_t const radius,
    Color const color
);
ColoredCircleClass const * ColoredCircleClass_instance(void);

#endif // COLOREDCIRCLE_H
