#include "Drawable.h"
#include <stdio.h>

/**
 *
 */
void Drawable_draw(Drawable const * const me) {
    return interfaceCall_(Drawable, draw, me);
}
static void draw(Drawable const * const me) {
    printf(".\n");
}

/**
 *
 */
DrawableOps const * DrawableOps_(void) {
    static DrawableOps const ops = {
        .draw = draw
    };

    return &ops;
}
