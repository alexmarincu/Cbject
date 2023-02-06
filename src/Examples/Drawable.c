#include "Drawable.h"
#include <stdio.h>

#define cbject_Class (Drawable, Shape)

void Drawable_init(
    Drawable * const drawable,
    Point origin,
    uint16_t const scale
) {
    Shape_init((Shape *)drawable, origin);
    drawable->scale = scale;
}

void Drawable_draw(Drawable const * const drawable) {
    cbject_invokeMethod(draw, drawable);
}

static void draw(Drawable const * const drawable) {
    assert("not implemented" && false);
    (void)(drawable);
}

DrawableClass const * DrawableClass_instance(void) {
    static DrawableClass klass;
    cbject_doOnce {
        cbject_Class_setup(&klass);
        klass.draw = draw;
    }
    return &klass;
}

#undef cbject_Class
