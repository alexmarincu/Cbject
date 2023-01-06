#include "Circle.h"
#include "Shape.h"
#include <stdio.h>
static cbject_Object * teardown(cbject_Object * object);
static float area(Shape const * const shape);
static void draw(Drawable const * const drawable);
CircleClass const * CircleClass_getInstance(void) {
    static CircleClass circleClass;
    cbject_doOnce {
        cbject_setUpClass(Circle, Shape, &circleClass);
        cbject_setUpInterfaceOf(Circle, Drawable, &circleClass);
        cbject_bindClassMethod(cbject_Object, teardown, &circleClass);
        cbject_bindInterfaceMethodOf(Circle, Drawable, draw, &circleClass);
        cbject_bindClassMethod(Shape, area, &circleClass);
    }
    return &circleClass;
}
Circle * Circle_init(
    Circle * const circle,
    Point origin,
    uint32_t radius
) {
    Shape_init((Shape *)circle, origin);
    cbject_setUpTraitOf(Circle, Drawable, circle, 0);
    circle->radius = radius;
    return circle;
}
static float area(Shape const * const shape) {
    Circle * circle = (Circle *)shape;
    return circle->radius * circle->radius * 3.14;
}
static void draw(Drawable const * const drawable) {
    Circle * circle = (Circle *)cbject_getObjectOfTrait(drawable);
    float const radius = circle->radius;
    float const tolerance = radius / 2;
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            float eq = x * x + y * y - radius * radius;
            printf(((eq < tolerance) && (eq > -tolerance)) ? "*" : " ");
        }
        printf("\n");
    }
}
static cbject_Object * teardown(cbject_Object * object) {
    return cbject_callMethodOfClass(Shape, cbject_Object, teardown, object);
}
