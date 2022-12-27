#include "Circle.h"
#include <stdio.h>
static x_Object * teardown(x_Object * object);
static float area(Shape const * const shape);
static void draw(Drawable const * const drawable);
CircleClass const * CircleClass_instance(void) {
    static CircleClass circleClass;
    x_doOnce {
        x_setUpClass(Circle, Shape, &circleClass);
        x_setUpInterfaceOf(Circle, Drawable, &circleClass);
        x_bindClassMethod(x_Object, teardown, &circleClass);
        x_bindInterfaceMethodOf(Circle, Drawable, draw, &circleClass);
        x_bindClassMethod(Shape, area, &circleClass);
    }
    return &circleClass;
}
Circle * Circle_init(
    Circle * const circle,
    Point origin,
    uint32_t radius
) {
    x_setUpObject(Circle, Shape, circle, origin);
    x_setUpTraitOf(Circle, Drawable, circle, 0);
    circle->radius = radius;
    return circle;
}
static float area(Shape const * const shape) {
    Circle * circle = x_castTo(Circle, shape);
    return circle->radius * circle->radius * 3.14;
}
static void draw(Drawable const * const drawable) {
    Circle * circle = x_castTo(Circle, x_objectOf(drawable));
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
static x_Object * teardown(x_Object * object) {
    return x_callClassMethod(Shape, x_Object, teardown, object);
}
