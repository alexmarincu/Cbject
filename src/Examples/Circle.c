#include "Circle.h"
#include <stdio.h>

/**
 * @brief
 * @param me
 * @return Circle*
 */
static Circle * copy(Circle const * const me) {
    Circle * rectangle = init_(Circle, new_(Circle), me->_iShape.origin, me->radius);
    return rectangle;
}

/**
 * @brief
 * @param me
 * @return float
 */
static float area(Circle const * const me) {
    return me->radius * me->radius * 3.14;
}

/**
 * @brief
 * @param me
 */
static void draw(Circle const * const me) {
    int const radius = me->radius;
    int const tolerance = radius / 2;

    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            int eq = x * x + y * y - radius * radius;
            printf(((eq < tolerance) && (eq > -tolerance)) ? "*" : " ");
        }

        printf("\r\n");
    }
}

/**
 * @brief
 * @param me
 * @param degrees
 */
void Circle_rotate(Circle const * const me, uint8_t const degrees) {
    printf("Circle rotate %d\n", degrees);
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
static void finalize(Circle * me) {
    superCall_(Object, finalize, me);
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
        operations._xObjectOperations.finalize = (ObjectOperation_finalize)finalize;
        operations._xObjectOperations.copy = (ObjectOperation_copy)copy;
        operations._iShapeOperations.area = (ShapeOperation_area)area;
        operations._iDrawableOperations.draw = (DrawableOperation_draw)draw;
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
