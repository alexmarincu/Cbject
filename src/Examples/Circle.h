#ifndef CIRCLE_H
#define CIRCLE_H
#include "Drawable.h"

typedef struct Circle Circle;
typedef struct CircleClass CircleClass;

struct Circle {
    Drawable super;
    uint32_t radius;
};

struct CircleClass {
    DrawableClass super;
};

Circle * Circle_init(
    Circle * const self,
    Point origin,
    uint32_t radius
);
CircleClass * CircleClass_instance(void);

#endif // CIRCLE_H
