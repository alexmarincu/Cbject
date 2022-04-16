#include "Rectangle.h"
#include <stdio.h>

/**
 * @brief Rectangle
 */
struct Rectangle {
    extend_(Object);
    inherit_(Shape);
    inherit_(Drawable);
    uint32_t width;
    uint32_t height;
};

static Object * deinit(Object * me);
static float area(Shape const * const me);
static void draw(Drawable const * const me);

RectangleOps const * RectangleOps_(void) {
    static RectangleOps ops;

    doOnce_ {
        ops.xObjectOps = *ObjectOps_();
        ops.xObjectOps.deinit = deinit;
        ops.iShapeOps.area = area;
        ops.iDrawableOps.draw = draw;
    }

    return &ops;
}

RectangleClass const * RectangleClass_(void) {
    static RectangleClass cls;

    doOnce_ {
        initClass_(toClass_(&cls), Rectangle, ObjectClass_());
        initInterface_(&to_(RectangleClass, &cls)->iShapeInterface, offsetof(Rectangle, iShape), &RectangleOps_()->iShapeOps);
        initInterface_(&to_(RectangleClass, &cls)->iDrawableInterface, offsetof(Rectangle, iDrawable), &RectangleOps_()->iDrawableOps);
    }

    return &cls;
}

Rectangle * Rectangle_init(Rectangle * me, Point origin, uint32_t width, uint32_t height) {
    initObject_(me, RectangleClass_());
    initObject_(&me->iShape, &((RectangleClass *)RectangleClass_())->iShapeInterface);
    initObject_(&me->iDrawable, &((RectangleClass *)RectangleClass_())->iDrawableInterface);
    me->iShape.origin = origin;
    me->width = width;
    me->height = height;
    return me;
}

uint32_t Rectangle_getWidth(Rectangle const * const me) {
    return me->width;
}

void Rectangle_setWidth(Rectangle * const me, uint32_t const width) {
    me->width = width;
}

uint32_t Rectangle_getHeight(Rectangle const * const me) {
    return me->height;
}

void Rectangle_setHeight(Rectangle * const me, uint32_t const height) {
    me->height = height;
}

void Rectangle_makeSquare(Rectangle * const me, uint32_t const edgeSize) {
    me->height = edgeSize;
    me->width = edgeSize;
}

static Object * deinit(Object * me) {
    return ObjectOps_()->deinit(me);
}

static float area(Shape const * const me) {
    Rectangle * Me = cast_(Rectangle, objectOf_(me));
    return Me->width * Me->height;
}

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

Shape * Rectangle_getShape(Rectangle * const me) {
    return &me->iShape;
}

Drawable * Rectangle_getDrawable(Rectangle * const me) {
    return &me->iDrawable;
}
