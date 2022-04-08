#include "Drawable.h"
#include <stdio.h>

/**
 * @brief Draws a drawable
 *
 * @param me The drawable's interface
 */
void Drawable_draw(Drawable const * const me) {
    return interfaceCall_(Drawable, draw, me);
}
static void draw(Drawable const * const me) {
    printf(".\n");
}

/**
 * @brief Gets reference to DrawableOperations
 * @remark At first call the initialization is done
 *
 * @return DrawableOperations const* The reference to DrawableOperations
 */
DrawableOperations const * DrawableOperations_(void) {
    static DrawableOperations const operations = {
        .draw = draw
    };

    return &operations;
}
