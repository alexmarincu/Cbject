#include "Drawable.h"
#include <stdio.h>
Drawable_Interface const * Drawable_Interface_(void) {
    static Drawable_Interface interface;
    doOnce_ {
        initInterface_(Module, &interface);
    };
    return &interface;
}
void Drawable_draw(Drawable const * const me) {
    return moduleMethodCall_(Drawable, draw, me);
}
Drawable * Drawable_init(
    Drawable * me
) {
    initModule_(Module, me);
    return me;
}