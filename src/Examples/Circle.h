#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Cbject/Cbject.h"
#include "Drawable.h"
#include "Shape.h"
typedef struct Circle_Class Circle_Class;
typedef struct Circle Circle;
struct Circle_Class {
    extends_(Shape_Class);
    implements_(Drawable_Interface);
};
struct Circle {
    extends_(Shape);
    implements_(Drawable);
    uint32_t radius;
};
Circle_Class const * Circle_Class_(void);
Circle * Circle_init(
    Circle * circle,
    Point origin,
    uint32_t radius
);
#endif // CIRCLE_H
