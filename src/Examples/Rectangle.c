#include "Rectangle.h"
#include <stdio.h>
/* @startuml(id=Rectangle)
object Rectangle {
    Shape s_Shape;
    Drawable ss_Drawable;
    uint32_t width;
    uint32_t height;
}
@enduml */
struct Rectangle {
    cbject_is(Shape);
    cbject_has(Drawable);
    uint32_t width;
    uint32_t height;
};
static cbject_Object * teardown(cbject_Object * object);
static float area(Shape const * const shape);
static void draw(Drawable const * const drawable);
RectangleClass const * RectangleClass_getInstance(void) {
    static RectangleClass rectangleClass;
    cbject_doOnce {
        cbject_setUpClass(Rectangle, Shape, &rectangleClass);
        cbject_setUpInterfaceOf(Rectangle, Drawable, &rectangleClass);
        cbject_bindClassMethod(cbject_Object, teardown, &rectangleClass);
        cbject_bindInterfaceMethodOf(Rectangle, Drawable, draw, &rectangleClass);
        cbject_bindClassMethod(Shape, area, &rectangleClass);
    }
    return &rectangleClass;
}
Rectangle * Rectangle_init(
    Rectangle * const rectangle,
    Point origin,
    uint32_t width,
    uint32_t height
) {
    Shape_init((Shape *)rectangle, origin);
    cbject_setUpTraitOf(Rectangle, Drawable, rectangle, 0);
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
static cbject_Object * teardown(cbject_Object * object) {
    return cbject_callMethodOfClass(Shape, cbject_Object, teardown, object);
}
static float area(Shape const * const shape) {
    Rectangle * rectangle = (Rectangle *)shape;
    return rectangle->width * rectangle->height;
}
static void draw(Drawable const * const drawable) {
    Rectangle * rectangle = (Rectangle *)cbject_getObjectOfTrait(drawable);
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
