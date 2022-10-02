#include "Drawable.h"
#include <stdio.h>
Drawable_Interface const * Drawable_Interface_(void) {
    static Drawable_Interface interface;
    doOnce_({
        initInterface_(Trait, &interface);
    });
    return &interface;
}
Drawable * Drawable_init(Drawable * const drawable) {
    initTrait_(Trait, drawable);
    return drawable;
}
void Drawable_draw(Drawable const * const drawable) {
    return traitMethodCall_(Drawable, draw, drawable);
}