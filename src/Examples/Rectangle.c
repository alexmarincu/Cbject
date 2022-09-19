#include "Rectangle.h"
#include <stdio.h>
/**
 * @brief Rectangle
 */
struct Rectangle {
    extends_(Object);
    implements_(Shape);
    implements_(Drawable);
    uint32_t width;
    uint32_t height;
};
static Object * deinit(Object * me);
static float area(Shape const * const me);
static void draw(Drawable const * const me);
Rectangle_Class const * Rectangle_Class_(void) {
    static Rectangle_Class class;
    doOnce_ {
        initClass_(&class, Rectangle, Object);
        initInterfaceOf_(&class, Rectangle, Rectangle, Shape);
        initInterfaceOf_(&class, Rectangle, Rectangle, Drawable);
    }
    return &class;
}
Rectangle_Operations const * Rectangle_Operations_(void) {
    static Rectangle_Operations operations;
    doOnce_ {
        inheritOperations_(&operations, Object);
        overrideOperation_(&operations, Object, deinit);
        overrideIOperation_(&operations, Rectangle, Shape, area);
        overrideIOperation_(&operations, Rectangle, Drawable, draw);
    }
    return &operations;
}
Rectangle * Rectangle_init(
    Rectangle * me,
    Point origin,
    uint32_t width,
    uint32_t height
) {
    initObject_(me, Rectangle);
    initIObjectOf_(me, Rectangle, Rectangle, Shape);
    initIObjectOf_(me, Rectangle, Rectangle, Drawable);
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
    return superCall_(Object, deinit, me);
}
static float area(Shape const * const me) {
    Rectangle * Me = (Rectangle *)rObjectOf_(me);
    return Me->width * Me->height;
}
static void draw(Drawable const * const me) {
    Rectangle * Me = (Rectangle *)rObjectOf_(me);
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
