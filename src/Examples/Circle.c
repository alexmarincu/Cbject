#include "Circle.h"
#include <stdio.h>

static Object * deinit(Object * me);
static float area(Shape const * const me);
static void draw(Drawable const * const me);

CircleOps const * CircleOps_(void) {
    static CircleOps ops;

    doOnce_ {
        ops.xObjectOps = *ObjectOps_();
        ops.xObjectOps.deinit = deinit;
        ops.iShapeOps.area = area;
        ops.iDrawableOps.draw = draw;
    }

    return &ops;
}

CircleClass const * CircleClass_(void) {
    static CircleClass cls;

    doOnce_ {
        initClass_(&cls, Circle, ObjectClass_());
        initInterface_(&cls.iShapeInterface, offsetof(Circle, iShape), &CircleOps_()->iShapeOps);
        initInterface_(&cls.iDrawableInterface, offsetof(Circle, iDrawable), &CircleOps_()->iDrawableOps);
    }

    return &cls;
}

Circle * Circle_init(Circle * me, Point origin, uint32_t radius) {
    initObject_(me, CircleClass_());
    initObject_(&me->iShape, &((CircleClass *)CircleClass_())->iShapeInterface);
    initObject_(&me->iDrawable, &((CircleClass *)CircleClass_())->iDrawableInterface);
    me->iShape.origin = origin;
    me->radius = radius;
    return me;
}

static float area(Shape const * const me) {
    Circle * Me = cast_(Circle, objectOf_(me));
    return Me->radius * Me->radius * 3.14;
}

static void draw(Drawable const * const me) {
    Circle * Me = cast_(Circle, objectOf_(me));
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
    return ObjectOps_()->deinit(me);
}
