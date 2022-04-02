#include "Circle.h"
#include <stdio.h>

/**
 * @brief
 *
 * @param this_
 * @return Circle*
 */
static Circle * copy(Circle const * const this_) {
    Circle * rectangle = Circle_init(new_(Circle), this_->_iShape.origin, this_->radius);
    return rectangle;
}

/**
 * @brief
 *
 * @param this_
 * @return float
 */
static float area(Circle const * const this_) {
    return this_->radius * this_->radius * 3.14;
}

/**
 * @brief
 *
 * @param this_
 */
static void draw(Circle const * const this_) {
    printf("draw circle: %d\n", this_->radius);
}

/**
 * @brief
 *
 * @param this_
 * @param degrees
 */
void Circle_rotate(Circle const * const this_, uint8_t const degrees) {
    printf("Circle rotate %d\n", degrees);
}

/**
 * @brief
 *
 * @param this_
 * @param params
 */
Circle * Circle_init(Circle * this_, Point origin, uint32_t radius) {
    initObject_(this_, CircleClass_());
    initInterface_(&this_->_iShape, this_, &CircleOperations_()->_iShapeOperations);
    initInterface_(&this_->_iDrawable, this_, &CircleOperations_()->_iDrawableOperations);
    this_->_iShape.origin = origin;
    this_->radius = radius;
    return this_;
}

/**
 * @brief
 *
 * @param this_
 */
static void finalize(Circle * this_) {
    superCall_(Object, finalize, this_);
}

/**
 * @brief
 *
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
 *
 * @return Class const*
 */
Class const * CircleClass_(void) {
    static Class class_;

    doOnce_({
        initClass_(&class_, Circle, ObjectClass_());
    });

    return &class_;
}
