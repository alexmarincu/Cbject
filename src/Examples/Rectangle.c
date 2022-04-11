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
    ObjectOperations_()->finalize(toObject_(cast_(Rectangle, me)));
}

/**
 * @brief
 * @param me
 * @return float
 */
static float area(Shape const * const me) {
    Rectangle * Me = cast_(Rectangle, objectOf_(me));
    return Me->width * Me->height;
}

/**
 * @brief
 * @param me
 */
static void draw(Drawable const * const me) {
    Rectangle * Me = cast_(Rectangle, objectOf_(me));

    for (uint8_t i = 0; i < Me->width; i++) {
        printf("--");
    }

    printf("\n");

    for (uint8_t i = 0; i < Me->height; i++) {
        printf("|");

        for (uint8_t i = 0; i < Me->width - 1; i++) {
            printf("  ");
        }

        printf("|\n");
    }

    for (uint8_t i = 0; i < Me->width; i++) {
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
    return &me->iShape;
}

/**
 * @brief
 * @param me
 * @return Drawable*
 */
Drawable * Rectangle_getDrawable(Rectangle * const me) {
    return &me->iDrawable;
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
    initObject_(me, Rectangle);
    initInterface_(&me->iShape, me, &RectangleOperations_()->iShapeOperations);
    initInterface_(&me->iDrawable, me, &RectangleOperations_()->iDrawableOperations);
    me->iShape.origin = origin;
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
Class const * RectangleClass_(void) {
    static Class class_;

    doOnce_ {
        initClass_(&class_, Rectangle, Object);
    }

    return &class_;
}
