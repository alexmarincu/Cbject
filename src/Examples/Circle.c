#include "Circle.h"
#include <stdio.h>

static Object * deinit(Object * me);
static float area(Shape const * const me);
static void draw(Drawable const * const me);

CircleOperations const * CircleOperations_(void) {
    static CircleOperations operations;

    doOnce_ {
        operations.xObjectOperations = *ObjectOperations_();
        operations.xObjectOperations.deinit = deinit;
        operations.iShapeOperations.area = area;
        operations.iDrawableOperations.draw = draw;
    }

    return &operations;
}

CircleClass const * CircleClass_(void) {
    static CircleClass cls;

    doOnce_ {
        initClass_(&cls, Circle, Object);
        initInterface_(&cls.iShapeInterface, offsetof(Circle, iShape), &CircleOperations_()->iShapeOperations);
        initInterface_(&cls.iDrawableInterface, offsetof(Circle, iDrawable), &CircleOperations_()->iDrawableOperations);
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
