#include "Rectangle.h"
#include <stdio.h>

/**
 * @brief
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
 * @param me
 * @return uint32_t
 */
uint32_t Rectangle_getWidth(Rectangle const * const me) {
    return me->width;
}

/**
 * @brief
 * @param me
 * @param width
 */
void Rectangle_setWidth(Rectangle * const me, uint32_t const width) {
    me->width = width;
}

/**
 * @brief
 * @param me
 * @return uint32_t
 */
uint32_t Rectangle_getHeight(Rectangle const * const me) {
    return me->height;
}

/**
 * @brief
 * @param me
 * @param height
 */
void Rectangle_setHeight(Rectangle * const me, uint32_t const height) {
    me->height = height;
}

/**
 * @brief
 * @param me
 * @param edgeSize
 */
void Rectangle_makeSquare(Rectangle * const me, uint32_t const edgeSize) {
    me->height = edgeSize;
    me->width = edgeSize;
}

/**
 * @brief
 * @param me
 */
static void finalize(Object * me) {
    Rectangle * _me = cast_(Rectangle, me);
    superCall_(Object, finalize, _me);
}

/**
 * @brief
 * @param me
 * @return float
 */
static float area(Shape const * const me) {
    Rectangle * _me = cast_(Rectangle, interfaceObjectOf_(me));
    return _me->width * _me->height;
}

/**
 * @brief
 * @param me
 */
static void draw(Drawable const * const me) {
    Rectangle * _me = cast_(Rectangle, interfaceObjectOf_(me));

    for (uint8_t i = 0; i < _me->width; i++) {
        printf("--");
    }

    printf("\n");

    for (uint8_t i = 0; i < _me->height; i++) {
        printf("|");

        for (uint8_t i = 0; i < _me->width - 1; i++) {
            printf("  ");
        }

        printf("|\n");
    }

    for (uint8_t i = 0; i < _me->width; i++) {
        printf("--");
    }

    printf("\n");
}

/**
 * @brief
 * @param me
 * @return Shape*
 */
Shape * Rectangle_getShape(Rectangle * const me) {
    return &me->_iShape;
}

/**
 * @brief
 * @param me
 * @return Drawable*
 */
Drawable * Rectangle_getDrawable(Rectangle * const me) {
    return &me->_iDrawable;
}

/**
 * @brief
 * @param me
 * @param origin
 * @param width
 * @param height
 * @return Rectangle*
 */
Rectangle * Rectangle_init(Rectangle * me, Point origin, uint32_t width, uint32_t height) {
    initObject_(me, RectangleClass_());
    initInterface_(&me->_iShape, me, &RectangleOperations_()->_iShapeOperations);
    initInterface_(&me->_iDrawable, me, &RectangleOperations_()->_iDrawableOperations);
    me->_iShape.origin = origin;
    me->width = width;
    me->height = height;
    return me;
}

/**
 * @brief
 * @return RectangleOperations const*
 */
RectangleOperations const * RectangleOperations_(void) {
    static RectangleOperations operations;

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
Class const * RectangleClass_(void) {
    static Class class_;

    doOnce_({
        initClass_(&class_, Rectangle, ObjectClass_());
    });

    return &class_;
}
