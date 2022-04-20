#include "Rectangle.h"
#include <stdio.h>

/**
 * @brief Rectangle
 */
struct Rectangle {
    super_(Object);
    mixin_(Shape);
    mixin_(Drawable);
    uint32_t width;
    uint32_t height;
};

static Object * deinit(Object * me);
static float area(Shape const * const me);
static void draw(Drawable const * const me);

RectangleInterface const * RectangleInterface_(void) {
    static RectangleInterface interface;

    doOnce_ {
        inheritInterface_(&interface, Object);
        overrideOperation_(&interface, Object, deinit);
        overrideMixinOperation_(&interface, Rectangle, Shape, area);
        overrideMixinOperation_(&interface, Rectangle, Drawable, draw);
    }

    return &interface;
}

RectangleClass const * RectangleClass_(void) {
    static RectangleClass cls;

    doOnce_ {
        initClass_(&cls, Rectangle, Object);
        initMixin_(&cls, Rectangle, Shape);
        initMixin_(&cls, Rectangle, Drawable);
    }

    return &cls;
}

Rectangle * Rectangle_init(Rectangle * me, Point origin, uint32_t width, uint32_t height) {
    initObject_(me, Rectangle);
    initMixinObject_(me, Rectangle, Shape);
    initMixinObject_(me, Rectangle, Drawable);
    me->mShape.origin = origin;
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
    return superCall_(Object, deinit, me);
}

static float area(Shape const * const me) {
    Rectangle * Me = to_(Rectangle, objectOf_(me));
    return Me->width * Me->height;
}

static void draw(Drawable const * const me) {
    Rectangle * Me = to_(Rectangle, objectOf_(me));

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
