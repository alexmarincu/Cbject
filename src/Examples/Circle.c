#include "Circle.h"
#include <stdio.h>
static Object * deinit(Object * me);
static float area(Shape const * const me);
static void draw(Drawable const * const me);
Circle_Class const * Circle_Class_(void) {
    static Circle_Class class;
    doOnce_ {
        initClass_(&class, Circle, Object);
        initInterfaceOf_(&class, Circle, Circle, Shape);
        initInterfaceOf_(&class, Circle, Circle, Drawable);
    }
    return &class;
}
Circle_Operations const * Circle_Operations_(void) {
    static Circle_Operations operations;
    doOnce_ {
        inheritOperations_(&operations, Object);
        overrideOperation_(&operations, Object, deinit);
        overrideIOperation_(&operations, Circle, Shape, area);
        overrideIOperation_(&operations, Circle, Drawable, draw);
    }
    return &operations;
}
Circle * Circle_init(Circle * me, Point origin, uint32_t radius) {
    Object_init((Object *)me, (Object_Interface *)Circle_Class_());
    initIObjectOf_(me, Circle, Circle, Shape);
    initIObjectOf_(me, Circle, Circle, Drawable);
    iObjectOf_(me, Circle, Shape)->origin = origin;
    me->radius = radius;
    return me;
}
static float area(Shape const * const me) {
    Circle * Me = (Circle *)rObjectOf_(me);
    return Me->radius * Me->radius * 3.14;
}
static void draw(Drawable const * const me) {
    Circle * Me = (Circle *)rObjectOf_(me);
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
static Object * deinit(Object * me) {
    return superCall_(Object, deinit, me);
}
