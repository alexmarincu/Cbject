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
 *
 */
uint32_t Rectangle_getWidth(Rectangle const * const me) {
    return me->width;
}

/**
 *
 */
void Rectangle_setWidth(Rectangle * const me, uint32_t const width) {
    me->width = width;
}

/**
 *
 */
uint32_t Rectangle_getHeight(Rectangle const * const me) {
    return me->height;
}

/**
 *
 */
void Rectangle_setHeight(Rectangle * const me, uint32_t const height) {
    me->height = height;
}

/**
 *
 */
void Rectangle_makeSquare(Rectangle * const me, uint32_t const edgeSize) {
    me->height = edgeSize;
    me->width = edgeSize;
}

/**
 *
 */
static Object * finalize(Object * me) {
    return ObjectOps_()->finalize(me);
}

/**
 *
 */
static float area(Shape const * const me) {
    Rectangle * Me = cast_(Rectangle, objectOf_(me));
    return Me->width * Me->height;
}

/**
 *
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
 *
 */
Shape * Rectangle_getShape(Rectangle * const me) {
    return &me->iShape;
}

/**
 *
 */
Drawable * Rectangle_getDrawable(Rectangle * const me) {
    return &me->iDrawable;
}

/**
 *
 */
Rectangle * Rectangle_init(Rectangle * me, Point origin, uint32_t width, uint32_t height) {
    initObject_(me, Rectangle);
    initInterface_(&me->iShape, me, &RectangleOps_()->iShapeOps);
    initInterface_(&me->iDrawable, me, &RectangleOps_()->iDrawableOps);
    me->iShape.origin = origin;
    me->width = width;
    me->height = height;
    return me;
}

/**
 *
 */
RectangleOps const * RectangleOps_(void) {
    static RectangleOps ops;

    doOnce_ {
        ops.xObjectOps = *ObjectOps_();
        ops.iDrawableOps = *DrawableOps_();
        ops.iShapeOps = *ShapeOps_();
        ops.xObjectOps.finalize = finalize;
        ops.iShapeOps.area = area;
        ops.iDrawableOps.draw = draw;
    }

    return &ops;
}

/**
 *
 */
Class const * RectangleClass_(void) {
    static Class cls;

    doOnce_ {
        initClass_(&cls, Rectangle, Object);
    }

    return &cls;
}
