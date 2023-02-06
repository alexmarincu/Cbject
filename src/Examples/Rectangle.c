#include "Rectangle.h"
#include <stdio.h>

#define cbject_Class (Rectangle, Drawable)

Rectangle * Rectangle_init(
    Rectangle * const rectangle,
    Point origin,
    uint32_t width,
    uint32_t height
) {
    Drawable_init(
        &rectangle->drawable,
        origin,
        0
    );
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

static cbject_Object * terminate(cbject_Object * object) {
    return cbject_invokeSuperMethod(cbject_Object, terminate, object);
}

static float area(Shape const * const shape) {
    Rectangle * rectangle = (Rectangle *)shape;
    return rectangle->width * rectangle->height;
}

static void draw(Drawable const * const drawable) {
    Rectangle * rectangle = (Rectangle *)drawable;
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

RectangleClass const * RectangleClass_instance(void) {
    static RectangleClass klass;
    cbject_doOnce {
        cbject_Class_setup(&klass);
        klass.drawableClass.shapeClass.objectClass.terminate = terminate;
        klass.drawableClass.shapeClass.area = area;
        klass.drawableClass.draw = draw;
    }
    return &klass;
}

#undef cbject_Class
