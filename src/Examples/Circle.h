#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Cbject/Cbject.h"
#include "Drawable.h"
#include "Shape.h"
typedefClass_(Circle);
struct CircleClass {
    extends_(ShapeClass);
    implements_(DrawableInterface);
};
struct Circle {
    extends_(Shape);
    implements_(Drawable);
    uint32_t radius;
};
CircleClass const * CircleClass_instance(void);
Circle * Circle_init(
    Circle * const circle,
    Point origin,
    uint32_t radius
);
#endif // CIRCLE_H
