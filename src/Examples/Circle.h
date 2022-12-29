#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Cbject/Cbject.h"
#include "Drawable.h"
#include "Shape.h"
x_typedefClass(Circle);
struct CircleClass {
    x_is(ShapeClass);
    x_has(DrawableInterface);
};
struct Circle {
    x_is(Shape);
    x_has(Drawable);
    uint32_t radius;
};
CircleClass const * CircleClass_instance(void);
Circle * Circle_init(
    Circle * const circle,
    Point origin,
    uint32_t radius
);
#endif // CIRCLE_H
