#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Cbject.h"

defMixin_(Drawable);

/**
 * @brief DrawableInterface
 */
struct DrawableInterface {
    void (*draw)(Drawable const * const me);
};

/**
 * @brief DrawableMixin
 */
struct DrawableMixin {
    super_(Mixin);
};

/**
 * @brief Drawable
 */
struct Drawable {
    super_(Object);
};

/**
 * @brief Draw a drawable
 * @param me The drawable object
 */
void Drawable_draw(Drawable const * const me);

#endif // DRAWABLE_H
