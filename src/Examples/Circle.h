#ifndef CIRCLE_H
#define CIRCLE_H
#include "Drawable.h"

typedef struct Circle Circle;
typedef struct Circle_Class Circle_Class;

struct Circle {
    Drawable super;
    uint32_t radius;
};

struct Circle_Class {
    Drawable_Class super;
};

Circle * Circle_init(
    Circle * const self,
    Point origin,
    uint32_t radius
);
Circle_Class * Circle_Class_instance(void);

#endif // CIRCLE_H
