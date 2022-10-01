#include "Circle.h"
#include <stdio.h>
static Object * teardown(Object * me);
static float area(Shape const * const me);
static void draw(Drawable const * const me);
Circle_Class const * Circle_Class_(void) {
    static Circle_Class class;
    doOnce_ {
        setUpClass_(Circle, Shape, &class);
        setUpInterface_(Circle, Drawable, &class);
        overrideObjectMethod_(Object, &class, teardown);
        overrideTraitMethod_(Circle, Drawable, &class, draw);
        overrideObjectMethod_(Shape, &class, area);
    }
    return &class;
}
Circle * Circle_init(
    Circle * me,
    Point origin,
    uint32_t radius
) {
    setUpObject_(Circle, Shape, me, origin);
    setUpTrait_(Circle, Drawable, me);
    me->radius = radius;
    return me;
}
static float area(Shape const * const me) {
    Circle * Me = to_(Circle, me);
    return Me->radius * Me->radius * 3.14;
}
static void draw(Drawable const * const me) {
    Circle * Me = to_(Circle, objectOf_(me));
    float const radius = Me->radius;
    float const tolerance = radius / 2;
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            float eq = x * x + y * y - radius * radius;
            printf(((eq < tolerance) && (eq > -tolerance)) ? "*" : " ");
        }
        printf("\n");
    }
}
static Object * teardown(Object * me) {
    return classMethodCall_(Object, teardown, me);
}
