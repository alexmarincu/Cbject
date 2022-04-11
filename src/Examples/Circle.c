#include "Circle.h"
#include <stdio.h>

/**
 * @brief
 * @param me
 * @return float
 */
static float area(Shape const * const me) {
    Circle * Me = cast_(Circle, objectOf_(me));
    return Me->radius * Me->radius * 3.14;
}

/**
 * @brief
 * @param me
 */
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

/**
 * @brief
 * @param me
 * @param params
 */
Circle * Circle_init(Circle * me, Point origin, uint32_t radius) {
    initObject_(me, Circle);
    initInterface_(&me->iShape, me, &CircleOperations_()->iShapeOperations);
    initInterface_(&me->iDrawable, me, &CircleOperations_()->iDrawableOperations);
    me->iShape.origin = origin;
    me->radius = radius;
    return me;
}

/**
 * @brief
 * @param me
 */
static void finalize(Object * me) {
    ObjectOperations_()->finalize(toObject_(cast_(Circle, me)));
}

/**
 * @brief
 * @return CircleOperations const*
 */
CircleOperations const * CircleOperations_(void) {
    static CircleOperations operations;

    doOnce_ {
        operations.xObjectOperations = *ObjectOperations_();
        operations.iDrawableOperations = *DrawableOperations_();
        operations.iShapeOperations = *ShapeOperations_();
        operations.xObjectOperations.finalize = finalize;
        operations.iShapeOperations.area = area;
        operations.iDrawableOperations.draw = draw;
    }

    return &operations;
}

/**
 * @brief
 * @return Class const*
 */
Class const * CircleClass_(void) {
    static Class class_;

    doOnce_ {
        initClass_(&class_, Circle, Object);
    }

    return &class_;
}
