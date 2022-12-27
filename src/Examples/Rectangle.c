#include "Rectangle.h"
#include <stdio.h>
/* @startuml(id=Rectangle)
object Rectangle {
    Shape eShape;
    Drawable iDrawable;
    uint32_t width;
    uint32_t height;
}
@enduml */
struct Rectangle {
    x_extends(Shape);
    x_implements(Drawable);
    uint32_t width;
    uint32_t height;
};
static x_Object * teardown(x_Object * object);
static float area(Shape const * const shape);
static void draw(Drawable const * const drawable);
RectangleClass const * RectangleClass_instance(void) {
    static RectangleClass rectangleClass;
    x_doOnce {
        x_setUpClass(Rectangle, Shape, &rectangleClass);
        x_setUpInterfaceOf(Rectangle, Drawable, &rectangleClass);
        x_bindClassMethod(x_Object, teardown, &rectangleClass);
        x_bindInterfaceMethodOf(Rectangle, Drawable, draw, &rectangleClass);
        x_bindClassMethod(Shape, area, &rectangleClass);
    }
    return &rectangleClass;
}
Rectangle * Rectangle_init(
    Rectangle * const rectangle,
    Point origin,
    uint32_t width,
    uint32_t height
) {
    x_setUpObject(Rectangle, Shape, rectangle, origin);
    x_setUpTraitOf(Rectangle, Drawable, rectangle, 0);
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
static x_Object * teardown(x_Object * object) {
    return x_callClassMethod(Shape, x_Object, teardown, object);
}
static float area(Shape const * const shape) {
    Rectangle * rectangle = x_castTo(Rectangle, shape);
    return rectangle->width * rectangle->height;
}
static void draw(Drawable const * const drawable) {
    Rectangle * rectangle = x_castTo(Rectangle, x_objectOf(drawable));
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
