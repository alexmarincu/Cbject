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
 * @brief Contains Drawable's operations (aka virtual functions)
 */
typedef struct DrawableOperations {
    void (*draw)(Drawable const * const me);
} DrawableOperations;

/**
 * @brief Gets reference to DrawableOperations
 * @remark At first call the initialization is done
 * @return DrawableOperations const* The reference to DrawableOperations
 */
DrawableOperations const * DrawableOperations_(void);

#endif // DRAWABLE_H
