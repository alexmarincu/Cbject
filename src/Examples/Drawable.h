#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Cbject.h"

/**
 * @brief interface Drawable
 */
typedef struct Drawable {
    extends_(Interface);
} Drawable;

/**
 * @brief Draws a drawable
 * @param me The drawable's interface reference
 */
void Drawable_draw(Drawable const * const me);

/**
 * @brief Contains Drawable's ops (aka virtual functions)
 */
typedef struct DrawableOps {
    void (*draw)(Drawable const * const me);
} DrawableOps;

/**
 * @brief Gets reference to DrawableOps
 * @remark At first call the initialization is done
 * @return DrawableOps const* The reference to DrawableOps
 */
DrawableOps const * DrawableOps_(void);

#endif // DRAWABLE_H
