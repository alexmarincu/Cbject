#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "../Cbject/Cbject.h"
/**
 * @brief Drawable
 */
typedef struct {
    extends_(Object);
} Drawable;
/**
 * @brief Drawable_Interface
 */
typedef struct {
    extends_(Object_Interface);
} Drawable_Interface;
/**
 * @brief Drawable_Operations
 */
typedef struct {
    void (*draw)(Drawable const * const me);
} Drawable_Operations;
/**
 * @brief Draw a drawable
 * @param me Drawable object reference
 */
void Drawable_draw(Drawable const * const me);
#endif // DRAWABLE_H
