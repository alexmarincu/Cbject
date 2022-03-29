#include "Circle.h"
#include <stdio.h>

/**
 * @brief
 *
 * @param this_
 * @return Circle*
 */
static Circle * copy(Circle const * const this_) {
    Circle * rectangle = Circle_init(new_(Circle), this_->_xShape.origin, this_->radius);
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
    initInterface_(&this_->_xShape, this_, &CircleOperations_()->_xShapeOperations);
    initInterface_(&this_->_xDrawable, this_, &CircleOperations_()->_xDrawableOperations);
    this_->_xShape.origin = origin;
    this_->radius = radius;
    return this_;
}

/**
 * @brief
 *
 * @param this_
 */
static void finalize(Circle * this_) {
    superOperationCall_(Object, finalize, this_);
}

/**
 * @brief
 *
 * @return CircleOperations const*
 */
CircleOperations const * CircleOperations_(void) {
    static CircleOperations operations;
    static bool isInitialized = false;

    if (!isInitialized) {
        operations._xSuper = *ObjectOperations_();
        operations._xDrawableOperations = *DrawableOperations_();
        operations._xShapeOperations = *ShapeOperations_();
        operations._xSuper.finalize = (ObjectOperation_finalize)finalize;
        operations._xSuper.copy = (ObjectOperation_copy)copy;
        operations._xShapeOperations.area = (ShapeOperation_area)area;
        operations._xDrawableOperations.draw = (DrawableOperation_draw)draw;
        isInitialized = true;
    }

    return &operations;
}

/**
 * @brief
 *
 * @return Class const*
 */
Class const * CircleClass_(void) {
    static Class class_;
    static bool isInitialized = false;

    if (!isInitialized) {
        initClass_(&class_, Circle, ObjectClass_());
        isInitialized = true;
    }

    return &class_;
}
