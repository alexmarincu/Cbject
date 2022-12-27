#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Cbject/Cbject.h"
#include "Drawable.h"
#include "Shape.h"
x_typedefClass(Circle);
struct CircleClass {
    x_extends(ShapeClass);
    x_implements(DrawableInterface);
};
struct Circle {
    x_extends(Shape);
    x_implements(Drawable);
    uint32_t radius;
};
CircleClass const * CircleClass_instance(void);
Circle * Circle_init(
    Circle * const circle,
    Point origin,
    uint32_t radius
);
#endif // CIRCLE_H
