#include "Drawable.h"
#include <stdio.h>
Drawable_Interface const * Drawable_Interface_(void) {
    static Drawable_Interface interface;
    doOnce_ {
        initInterface_(Trait, &interface);
    };
    return &interface;
}
Drawable * Drawable_init(Drawable * me) {
    initTrait_(Trait, me);
    return me;
}
void Drawable_draw(Drawable const * const me) {
    return traitMethodCall_(Drawable, draw, me);
}