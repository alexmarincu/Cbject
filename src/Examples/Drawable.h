#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "../Cbject/Cbject.h"

/**
 * @brief DrawableType
 */
typedef struct {
    extends_(Type);
} DrawableType;

/**
 * @brief Drawable
 */
typedef struct {
    extends_(Object);
} Drawable;

/**
 * @brief DrawableInterface
 */
typedef struct {
    void (*draw)(Drawable const * const me);
} DrawableInterface;

/**
 * @brief Draw a drawable
 * @param me Drawable object reference
 */
void Drawable_draw(Drawable const * const me);

#endif // DRAWABLE_H
