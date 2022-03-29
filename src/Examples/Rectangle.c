#include "Rectangle.h"
#include <stdio.h>

/**
 * @brief
 *
 */
struct Rectangle {
    extends_(Object);
    contains_(Shape);
    contains_(Drawable);
    uint32_t width;
    uint32_t height;
};

/**
 * @brief
 *
 * @param this_
 * @return uint32_t
 */
uint32_t Rectangle_getWidth(Rectangle const * const this_) {
    return this_->width;
}

/**
 * @brief
 *
 * @param this_
 * @param width
 */
void Rectangle_setWidth(Rectangle * const this_, uint32_t const width) {
    this_->width = width;
}

/**
 * @brief
 *
 * @param this_
 * @return uint32_t
 */
uint32_t Rectangle_getHeight(Rectangle const * const this_) {
    return this_->height;
}

/**
 * @brief
 *
 * @param this_
 * @param height
 */
void Rectangle_setHeight(Rectangle * const this_, uint32_t const height) {
    this_->height = height;
}

/**
 * @brief
 *
 * @param this_
 * @param edgeSize
 */
void Rectangle_makeSquare(Rectangle * const this_, uint32_t const edgeSize) {
    this_->height = edgeSize;
    this_->width = edgeSize;
}

/**
 * @brief
 *
 * @param this_
 */
static void finalize(Rectangle * this_) {
    superOperationCall_(Object, finalize, this_);
}

/**
 * @brief
 *
 * @param this_
 * @return Rectangle*
 */
static Rectangle * copy(Rectangle const * const this_) {
    Rectangle * rectangle =
        Rectangle_init(new_(Rectangle), this_->_xShape.origin, this_->height, this_->width);
    return rectangle;
}

/**
 * @brief
 *
 * @param this_
 * @return float
 */
static float area(Rectangle const * const this_) {
    return this_->width * this_->height;
}

/**
 * @brief
 *
 * @param this_
 */
static void draw(Rectangle const * const this_) {
    printf("draw rectangle: %d, %d\n", this_->_xShape.origin.x, this_->_xShape.origin.y);
}

/**
 * @brief
 *
 * @param this_
 * @return Shape*
 */
Shape * Rectangle_getShape(Rectangle * const this_) {
    return &this_->_xShape;
}

/**
 * @brief
 *
 * @param this_
 * @return Drawable*
 */
Drawable * Rectangle_getDrawable(Rectangle * const this_) {
    return &this_->_xDrawable;
}

/**
 * @brief
 *
 * @param this_
 * @param origin
 * @param width
 * @param height
 * @return Rectangle*
 */
Rectangle * Rectangle_init(Rectangle * this_, Point origin, uint32_t width, uint32_t height) {
    initObject_(this_, RectangleClass_());
    initInterface_(&this_->_xShape, this_, &RectangleOperations_()->_xShapeOperations);
    initInterface_(&this_->_xDrawable, this_, &RectangleOperations_()->_xDrawableOperations);
    this_->_xShape.origin = origin;
    this_->width = width;
    this_->height = height;
    return this_;
}

/**
 * @brief
 *
 * @return RectangleOperations const*
 */
RectangleOperations const * RectangleOperations_(void) {
    static RectangleOperations operations;
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
Class const * RectangleClass_(void) {
    static Class class_;
    static bool isInitialized = false;

    if (!isInitialized) {
        initClass_(&class_, Rectangle, ObjectClass_());
        isInitialized = true;
    }

    return &class_;
}
