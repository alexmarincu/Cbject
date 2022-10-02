#include "Rectangle.h"
#include <stdio.h>
/* @startuml(id=Rectangle)
object Rectangle {
    Shape super;
    Drawable iDrawable;
    uint32_t width;
    uint32_t height;
}
@enduml */
struct Rectangle {
    extends_(Shape);
    implements_(Drawable);
    uint32_t width;
    uint32_t height;
};
static Object * teardown(Object * object);
static float area(Shape const * const shape);
static void draw(Drawable const * const drawable);
Rectangle_Class const * Rectangle_Class_(void) {
    static Rectangle_Class class;
    doOnce_({
        setUpClass_(Rectangle, Shape, &class);
        setUpInterface_(Rectangle, Drawable, &class);
        overrideClassMethod_(Object, &class, teardown);
        overrideInterfaceMethod_(Rectangle, Drawable, &class, draw);
        overrideClassMethod_(Shape, &class, area);
    });
    return &class;
}
Rectangle * Rectangle_init(
    Rectangle * rectangle,
    Point origin,
    uint32_t width,
    uint32_t height
) {
    setUpObject_(Rectangle, Shape, rectangle, origin);
    setUpTrait_(Rectangle, Drawable, rectangle);
    rectangle->width = width;
    rectangle->height = height;
    return rectangle;
}
uint32_t Rectangle_getWidth(Rectangle const * const rectangle) {
    return rectangle->width;
}
void Rectangle_setWidth(Rectangle * const rectangle, uint32_t const width) {
    rectangle->width = width;
}
uint32_t Rectangle_getHeight(Rectangle const * const rectangle) {
    return rectangle->height;
}
void Rectangle_setHeight(Rectangle * const rectangle, uint32_t const height) {
    rectangle->height = height;
}
void Rectangle_makeSquare(Rectangle * const rectangle, uint32_t const edgeSize) {
    rectangle->height = edgeSize;
    rectangle->width = edgeSize;
}
static Object * teardown(Object * object) {
    return classMethodCall_(Shape, Object, teardown, object);
}
static float area(Shape const * const shape) {
    Rectangle * rectangle = to_(Rectangle, shape);
    return rectangle->width * rectangle->height;
}
static void draw(Drawable const * const drawable) {
    Rectangle * rectangle = to_(Rectangle, objectOf_(drawable));
    for (uint8_t i = 0; i < rectangle->width; i++) {
        printf("--");
    }
    printf("\n");
    for (uint8_t i = 0; i < rectangle->height; i++) {
        printf("|");
        for (uint8_t i = 0; i < rectangle->width - 1; i++) {
            printf("  ");
        }
        printf("|\n");
    }
    for (uint8_t i = 0; i < rectangle->width; i++) {
        printf("--");
    }
    printf("\n");
}
