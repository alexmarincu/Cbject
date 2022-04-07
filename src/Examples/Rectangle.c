#include "Rectangle.h"
#include <stdio.h>

/**
 * @brief
 *
 */
struct Rectangle {
    extends_(Object);
    inherits_(Shape);
    inherits_(Drawable);
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
    superCall_(Object, finalize, this_);
}

/**
 * @brief
 *
 * @param this_
 * @return Rectangle*
 */
static Rectangle * copy(Rectangle const * const this_) {
    Rectangle * rectangle =
        Rectangle_init(new_(Rectangle), this_->_iShape.origin, this_->height, this_->width);
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
    for (uint8_t i = 0; i < this_->width; i++) {
        printf("--");
    }

    printf("\n");

    for (uint8_t i = 0; i < this_->height; i++) {
        printf("|");

        for (uint8_t i = 0; i < this_->width - 1; i++) {
            printf("  ");
        }

        printf("|\n");
    }

    for (uint8_t i = 0; i < this_->width; i++) {
        printf("--");
    }

    printf("\n");
}

/**
 * @brief
 *
 * @param this_
 * @return Shape*
 */
Shape * Rectangle_getShape(Rectangle * const this_) {
    return &this_->_iShape;
}

/**
 * @brief
 *
 * @param this_
 * @return Drawable*
 */
Drawable * Rectangle_getDrawable(Rectangle * const this_) {
    return &this_->_iDrawable;
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
    initInterface_(&this_->_iShape, this_, &RectangleOperations_()->_iShapeOperations);
    initInterface_(&this_->_iDrawable, this_, &RectangleOperations_()->_iDrawableOperations);
    this_->_iShape.origin = origin;
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
Class const * RectangleClass_(void) {
    static Class class_;

    doOnce_({
        initClass_(&class_, Rectangle, ObjectClass_());
    });

    return &class_;
}
