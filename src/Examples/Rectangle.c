#include "Rectangle.h"
#include <stdio.h>

#define cbject_Class (Rectangle, Drawable)
cbject_allocPool(1);

Rectangle * Rectangle_init(
    Rectangle * const self,
    Point origin,
    uint32_t width,
    uint32_t height
) {
    Drawable_init(
        (Drawable *)self,
        origin,
        0
    );
    self->width = width;
    self->height = height;
    return self;
}

uint32_t Rectangle_getWidth(Rectangle const * const self) {
    return self->width;
}

void Rectangle_setWidth(Rectangle * const self, uint32_t const width) {
    self->width = width;
}
uint32_t Rectangle_getHeight(Rectangle const * const self) {
    return self->height;
}

void Rectangle_setHeight(Rectangle * const self, uint32_t const height) {
    self->height = height;
}

void Rectangle_makeSquare(Rectangle * const self, uint32_t const edgeSize) {
    self->height = edgeSize;
    self->width = edgeSize;
}

static cbject_Object * terminate(cbject_Object * self) {
    return cbject_invokeSuperMethod(cbject_Object, terminate, self);
}

static float area(Shape const * const self) {
    Rectangle * rectangle = (Rectangle *)self;
    return rectangle->width * rectangle->height;
}

static void draw(Drawable const * const self) {
    Rectangle * rectangle = (Rectangle *)self;
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

Rectangle_Class * Rectangle_Class_instance(void) {
    static Rectangle_Class self;
    cbject_doOnce {
        cbject_Class_setup(&self);
        ((cbject_Object_Class *)&self)->terminate = terminate;
        ((Shape_Class *)&self)->area = area;
        ((Drawable_Class *)&self)->draw = draw;
    }
    return &self;
}

#undef cbject_Class
