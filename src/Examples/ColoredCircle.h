#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Circle.h"
#include "Color.h"

typedef struct ColoredCircle ColoredCircle;
typedef struct ColoredCircle_Class ColoredCircle_Class;

struct ColoredCircle {
    Circle super;
    Color color;
};

struct ColoredCircle_Class {
    Circle_Class super;
};

ColoredCircle * ColoredCircle_init(
    ColoredCircle * const self,
    Point const origin,
    uint32_t const radius,
    Color const color
);
ColoredCircle_Class * ColoredCircle_Class_instance(void);

#endif // COLOREDCIRCLE_H
