#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Cbject.h"

interface_(Drawable);

/**
 * @brief DrawableOps
 */
struct DrawableOps {
    void (*draw)(Drawable const * const me);
};

/**
 * @brief DrawableInterface
 */
struct DrawableInterface {
    extend_(Interface);
};

/**
 * @brief Drawable
 */
struct Drawable {
    extend_(Object);
};

/**
 * @brief Draw a drawable
 * @param me The drawable object
 */
void Drawable_draw(Drawable const * const me);

#endif // DRAWABLE_H
