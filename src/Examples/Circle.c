#include "Circle.h"
#include <stdio.h>

static Object * deinit(Object * me);
static float area(Shape const * const me);
static void draw(Drawable const * const me);

CircleOperations const * CircleOperations_(void) {
    static CircleOperations operations;

    doOnce_ {
        inheritOperationsOf_(Object, &operations);
        overrideOperation_(Object, deinit, &operations);
        overrideInterfaceOperation_(Circle, Shape, area, &operations);
        overrideInterfaceOperation_(Circle, Drawable, draw, &operations);
    }

    return &operations;
}

CircleClass const * CircleClass_(void) {
    static CircleClass cls;

    doOnce_ {
        initClass_(&cls, Circle, Object);
        initChildInterface_(&cls, Circle, Circle, Shape);
        initChildInterface_(&cls, Circle, Circle, Drawable);
    }

    return &cls;
}

Circle * Circle_init(Circle * me, Point origin, uint32_t radius) {
    initObject_(me, Circle);
    initChildObject_(me, Circle, Circle, Shape);
    initChildObject_(me, Circle, Circle, Drawable);
    me->iShape.origin = origin;
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
    return ObjectOperations_()->deinit(me);
}
