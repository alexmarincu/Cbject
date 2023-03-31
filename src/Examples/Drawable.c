#include "Drawable.h"
#include <stdio.h>

#define cbject_Class (Drawable, Shape)
cbject_noPool;

void Drawable_init(
    Drawable * const self,
    Point origin,
    uint16_t const scale
) {
    Shape_init((Shape *)self, origin);
    self->scale = scale;
}

void Drawable_draw(Drawable const * const self) {
    cbject_invokeMethod(draw, self);
}

static void draw(Drawable const * const self) {
    assert("not implemented" && false);
    (void)(self);
}

Drawable_Class * Drawable_Class_instance(void) {
    static Drawable_Class self;
    cbject_doOnce {
        cbject_Class_setup(&self);
        self.draw = draw;
    }
    return &self;
}

#undef cbject_Class
