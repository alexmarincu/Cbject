#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "../Cbject/Cbject.h"
/**
 * @brief Drawable
 */
typedef struct {
    extends_(Trait);
} Drawable;
/**
 * @brief Drawable_Interface
 */
typedef struct {
    extends_(Trait_Interface);
    void (*draw)(Drawable const * const me);
} Drawable_Interface;
/**
 * @brief Drawable_Interface
 * @return Drawable_Interface const*
 */
Drawable_Interface const * Drawable_Interface_(void);
/**
 * @brief Draw a drawable
 * @param me Drawable object reference
 */
void Drawable_draw(Drawable const * const me);
/**
 * @brief
 * @param me
 * @param origin
 * @param width
 * @param height
 * @return Rectangle*
 */
Drawable * Drawable_init(
    Drawable * me
);
#endif // DRAWABLE_H
