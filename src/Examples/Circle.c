#include "Circle.h"
#include <stdio.h>

/**
 * @brief
 * @param me
 * @return float
 */
static float area(Shape const * const me) {
    Circle * _me = cast_(Circle, interfaceObjectOf_(me));
    return _me->radius * _me->radius * 3.14;
}

/**
 * @brief
 * @param me
 */
static void draw(Drawable const * const me) {
    Circle * _me = cast_(Circle, interfaceObjectOf_(me));
    float const radius = _me->radius;
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
    initObject_(me, CircleClass_());
    initInterface_(&me->_iShape, me, &CircleOperations_()->_iShapeOperations);
    initInterface_(&me->_iDrawable, me, &CircleOperations_()->_iDrawableOperations);
    me->_iShape.origin = origin;
    me->radius = radius;
    return me;
}

/**
 * @brief
 * @param me
 */
static void finalize(Object * me) {
    Circle * _me = cast_(Circle, me);
    superCall_(Object, finalize, _me);
}

/**
 * @brief
 * @return CircleOperations const*
 */
CircleOperations const * CircleOperations_(void) {
    static CircleOperations operations;

    doOnce_({
        operations._xObjectOperations = *ObjectOperations_();
        operations._iDrawableOperations = *DrawableOperations_();
        operations._iShapeOperations = *ShapeOperations_();
        operations._xObjectOperations.finalize = finalize;
        operations._iShapeOperations.area = area;
        operations._iDrawableOperations.draw = draw;
    });

    return &operations;
}

/**
 * @brief
 * @return Class const*
 */
Class const * CircleClass_(void) {
    static Class class_;

    doOnce_({
        initClass_(&class_, Circle, ObjectClass_());
    });

    return &class_;
}
