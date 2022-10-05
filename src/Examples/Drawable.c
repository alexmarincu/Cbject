#include "Drawable.h"
#include <stdio.h>
static void draw(Drawable const * const drawable);
DrawableInterface const * DrawableInterface_instance(void) {
    static DrawableInterface interface;
    return &interface;
}
void DrawableInterface_init(void) {
    setUpInterface_(Drawable, Trait);
    bindInterfaceMethod_(Drawable, Drawable, draw);
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
    assert_("Drawable_draw not implemented" && false);
}