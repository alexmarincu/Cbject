#include "Circle.h"
#include <stdio.h>
static Object * teardown(Object * object);
static float area(Shape const * const shape);
static void draw(Drawable const * const drawable);
CircleClass const * CircleClass_instance(void) {
    static CircleClass class;
    return &class;
}
void CircleClass_init(void) {
    setUpClass_(Circle, Shape);
    setUpInterfaceOf_(Circle, Drawable);
    bindClassMethod_(Circle, Object, teardown);
    bindInterfaceMethodOf_(Circle, Circle, Drawable, draw);
    bindClassMethod_(Circle, Shape, area);
}
Circle * Circle_init(
    Circle * circle,
    Point origin,
    uint32_t radius
) {
    setUpObject_(Circle, Shape, circle, origin);
    setUpTraitOf_(Circle, Drawable, circle, 0);
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
