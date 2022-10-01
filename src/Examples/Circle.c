#include "Circle.h"
#include <stdio.h>
static Object * teardown(Object * object);
static float area(Shape const * const shape);
static void draw(Drawable const * const drawable);
Circle_Class const * Circle_Class_(void) {
    static Circle_Class class;
    doOnce_ {
        setUpClass_(Circle, Shape, &class);
        setUpInterface_(Circle, Drawable, &class);
        overrideClassMethod_(Object, &class, teardown);
        overrideInterfaceMethod_(Circle, Drawable, &class, draw);
        overrideClassMethod_(Shape, &class, area);
    }
    return &class;
}
Circle * Circle_init(
    Circle * circle,
    Point origin,
    uint32_t radius
) {
    setUpObject_(Circle, Shape, circle, origin);
    setUpTrait_(Circle, Drawable, circle);
    circle->radius = radius;
    return circle;
}
static float area(Shape const * const shape) {
    Circle * circle = to_(Circle, shape);
    return circle->radius * circle->radius * 3.14;
}
static void draw(Drawable const * const drawable) {
    Circle * circle = to_(Circle, objectOf_(drawable));
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
static Object * teardown(Object * object) {
    return classMethodCall_(Shape, Object, teardown, object);
}
