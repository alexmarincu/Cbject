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
        overrideMixinOperation_(&interface, Circle, Shape, area);
        overrideMixinOperation_(&interface, Circle, Drawable, draw);
    }

    return &interface;
}

CircleClass const * CircleClass_(void) {
    static CircleClass cls;

    doOnce_ {
        initClass_(&cls, Circle, Object);
        initMixin_(&cls, Circle, Shape);
        initMixin_(&cls, Circle, Drawable);
    }

    return &cls;
}

Circle * Circle_init(Circle * me, Point origin, uint32_t radius) {
    initObject_(me, Circle);
    initMixinObject_(me, Circle, Shape);
    initMixinObject_(me, Circle, Drawable);
    me->mShape.origin = origin;
    me->radius = radius;
    return me;
}

static float area(Shape const * const me) {
    Circle * Me = to_(Circle, objectOf_(me));
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

static Object * deinit(Object * me) {
    return superCall_(Object, deinit, me);
}
