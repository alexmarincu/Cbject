#include "Circle.h"
#include <stdio.h>

static Object * deinit(Object * me);
static float area(Shape const * const me);
static void draw(Drawable const * const me);

CircleInterface const * CircleInterface_(void) {
    static CircleInterface interface;

    doOnce_ {
        inheritInterface_(&interface, Object);
        overrideOperation_(&interface, Object, deinit);
        overrideNestedOperation_(&interface, Circle, Shape, area);
        overrideNestedOperation_(&interface, Circle, Drawable, draw);
    }

    return &interface;
}

CircleClass const * CircleClass_(void) {
    static CircleClass cls;

    doOnce_ {
        initClass_(&cls, Circle, Object);
        initNestedType_(&cls, Circle, Shape);
        initNestedType_(&cls, Circle, Drawable);
    }

    return &cls;
}

Circle * Circle_init(Circle * me, Point origin, uint32_t radius) {
    initObject_(me, Circle);
    initNestedObject_(me, Circle, Shape);
    initNestedObject_(me, Circle, Drawable);
    nestedObjectOf_(me, Circle, Shape)->origin = origin;
    me->radius = radius;
    return me;
}

static float area(Shape const * const me) {
    Circle * Me = to_(Circle, parentObjectOf_(me));
    return Me->radius * Me->radius * 3.14;
}

static void draw(Drawable const * const me) {
    Circle * Me = to_(Circle, parentObjectOf_(me));
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
