#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Cbject.h"

/**
 * @brief
 *
 */
typedef struct Drawable {
    interface_;
} Drawable;

/**
 * @brief
 *
 * @param this_
 */
void Drawable_draw(Drawable const * const this_);
typedef void (*DrawableOperation_draw)(Drawable const * const this_);

/**
 * @brief
 *
 */
typedef struct DrawableOperations {
    DrawableOperation_draw draw;
} DrawableOperations;

/**
 * @brief
 *
 * @return DrawableOperations const*
 */
DrawableOperations const * DrawableOperations_(void);

#endif // DRAWABLE_H
