#ifndef CIRCLE_H
#define CIRCLE_H
#include "../cbject/cbject.h"
#include "Drawable.h"
#include "Shape.h"
cbject_typedefClass(Circle);
struct CircleClass {
    cbject_is(ShapeClass);
    cbject_has(DrawableInterface);
};
struct Circle {
    cbject_is(Shape);
    cbject_has(Drawable);
    uint32_t radius;
};
CircleClass const * CircleClass_getInstance(void);
Circle * Circle_init(
    Circle * const circle,
    Point origin,
    uint32_t radius
);
#endif // CIRCLE_H
