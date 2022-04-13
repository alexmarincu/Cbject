#include "Circle.h"
#include <stdio.h>

/**
 *
 */
static float area(Shape const * const me) {
    Circle * Me = cast_(Circle, objectOf_(me));
    return Me->radius * Me->radius * 3.14;
}

/**
 *
 */
static void draw(Drawable const * const me) {
    Circle * Me = cast_(Circle, objectOf_(me));
    DrawableOps_()->draw(me);
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

/**
 *
 */
Circle * Circle_init(Circle * me, Point origin, uint32_t radius) {
    initObject_(me, Circle);
    initInterface_(&me->iShape, offsetof(Circle, iShape), &CircleOps_()->iShapeOps);
    initInterface_(&me->iDrawable, offsetof(Circle, iDrawable), &CircleOps_()->iDrawableOps);
    me->iShape.origin = origin;
    me->radius = radius;
    return me;
}

/**
 *
 */
static Object * deinit(Object * me) {
    return ObjectOps_()->deinit(me);
}

/**
 *
 */
CircleOps const * CircleOps_(void) {
    static CircleOps ops;

    doOnce_ {
        ops.xObjectOps = *ObjectOps_();
        ops.iDrawableOps = *DrawableOps_();
        ops.iShapeOps = *ShapeOps_();
        ops.xObjectOps.deinit = deinit;
        ops.iShapeOps.area = area;
        ops.iDrawableOps.draw = draw;
    }

    return &ops;
}

/**
 *
 */
Class const * CircleClass_(void) {
    static Class cls;

    doOnce_ {
        initClass_(&cls, Circle, Object);
    }

    return &cls;
}
