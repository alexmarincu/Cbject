#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

typedef struct ColoredCircle ColoredCircle;
typedef struct ColoredCircleClass ColoredCircleClass;

struct ColoredCircle {
    Circle super;
    Color color;
};

struct ColoredCircleClass {
    CircleClass super;
};

ColoredCircle * ColoredCircle_init(
    ColoredCircle * const self,
    Point const origin,
    uint32_t const radius,
    Color const color
);
ColoredCircleClass * ColoredCircleClass_instance(void);

#endif // COLOREDCIRCLE_H
