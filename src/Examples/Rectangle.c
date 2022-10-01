#include "Rectangle.h"
#include <stdio.h>
struct Rectangle {
    extends_(Shape);
    implements_(Drawable);
    uint32_t width;
    uint32_t height;
};
static Object * teardown(Object * me);
static float area(Shape const * const me);
static void draw(Drawable const * const me);
Rectangle_Class const * Rectangle_Class_(void) {
    static Rectangle_Class class;
    doOnce_ {
        setUpClass_(Rectangle, Shape, &class);
        setUpInterface_(Rectangle, Drawable, &class);
        overrideObjectMethod_(Object, &class, teardown);
        overrideTraitMethod_(Rectangle, Drawable, &class, draw);
        overrideObjectMethod_(Shape, &class, area);
    }
    return &class;
}
Rectangle * Rectangle_init(
    Rectangle * me,
    Point origin,
    uint32_t width,
    uint32_t height
) {
    setUpObject_(Rectangle, Shape, me, origin);
    setUpTrait_(Rectangle, Drawable, me);
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
static Object * teardown(Object * me) {
    return superObjectMethodCall_(Object, teardown, me);
}
static float area(Shape const * const me) {
    Rectangle * Me = to_(Rectangle, me);
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
