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
DrawableOperations const * DrawableOperations_(void) {
    static DrawableOperations const operations = {
        .draw = draw
    };

    return &operations;
}
