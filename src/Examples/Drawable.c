#include "Drawable.h"

/**
 * @brief
 *
 * @param this_
 */
void Drawable_draw(Drawable const * const this_) {
    return interfaceCall_(Drawable, draw, this_);
}
static void draw(Drawable const * const this_) {
    assert_(false && "function not overriden");
}

/**
 * @brief
 *
 * @return DrawableOperations const*
 */
DrawableOperations const * DrawableOperations_(void) {
    static DrawableOperations const operations = {
        .draw = draw
    };

    return &operations;
}
