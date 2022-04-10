#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Cbject.h"

/**
 * @brief interface Drawable
 */
typedef struct Drawable {
    extends_(Interface);
} Drawable;

void Drawable_draw(Drawable const * const me);

/**
 * @brief Contains Drawable's operations (aka virtual functions)
 */
typedef struct DrawableOperations {
    void (*draw)(Drawable const * const me);
} DrawableOperations;

DrawableOperations const * DrawableOperations_(void);

#endif // DRAWABLE_H
