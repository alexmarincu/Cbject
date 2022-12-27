#include "Drawable.h"
#include <stdio.h>
static void draw(Drawable const * const drawable);
DrawableInterface const * DrawableInterface_instance(void) {
    static DrawableInterface drawableInterface;
    x_doOnce {
        x_setUpInterface(Drawable, x_Trait, &drawableInterface);
        x_bindInterfaceMethod(Drawable, draw, &drawableInterface);
    }
    return &drawableInterface;
}
void Drawable_init(Drawable * const drawable, uint16_t const scale) {
    x_initTrait(x_Trait, drawable);
    drawable->scale = scale;
}
void Drawable_draw(Drawable const * const drawable) {
    x_callTraitMethod(Drawable, draw, drawable);
}
static void draw(Drawable const * const drawable) {
    x_ignore(drawable);
    assert("Drawable_draw not implemented" && false);
}