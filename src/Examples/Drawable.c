#include "Drawable.h"
#include <stdio.h>
static void draw(Drawable const * const drawable);
DrawableInterface const * DrawableInterface_getInstance(void) {
    static DrawableInterface drawableInterface;
    cbject_doOnce {
        cbject_setUpInterface(Drawable, cbject_Trait, &drawableInterface);
        cbject_bindInterfaceMethod(Drawable, draw, &drawableInterface);
    }
    return &drawableInterface;
}
void Drawable_init(Drawable * const drawable, uint16_t const scale) {
    cbject_initTrait(cbject_Trait, drawable);
    drawable->scale = scale;
}
void Drawable_draw(Drawable const * const drawable) {
    cbject_callMethodOfTrait(Drawable, draw, drawable);
}
static void draw(Drawable const * const drawable) {
    (void)(drawable);
    assert("Drawable_draw not implemented" && false);
}