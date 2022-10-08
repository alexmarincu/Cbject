#include "Drawable.h"
#include <stdio.h>
static void draw(Drawable const * const drawable);
DrawableInterface const * DrawableInterface_instance(void) {
    static DrawableInterface interface;
    doOnce_ {
        setUpInterface_(Trait, &interface);
        bindInterfaceMethod_(Drawable, draw, &interface);
    }
    return &interface;
}
void Drawable_init(Drawable * const drawable, uint16_t const scale) {
    initTrait_(Trait, drawable);
    drawable->scale = scale;
}
void Drawable_draw(Drawable const * const drawable) {
    traitMethodCall_(Drawable, draw, drawable);
}
static void draw(Drawable const * const drawable) {
    ignore_(drawable);
    assert("Drawable_draw not implemented" && false);
}