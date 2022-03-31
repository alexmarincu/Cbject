#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Cbject.h"
#include "Drawable.h"
#include "Shape.h"

/**
 * @brief
 *
 */
typedef struct Rectangle Rectangle;

/**
 * @brief
 *
 * @param this_
 * @param origin
 * @param width
 * @param height
 * @return Rectangle*
 */
Rectangle * Rectangle_init(Rectangle * this_, Point origin, uint32_t width, uint32_t height);

/**
 * @brief
 *
 * @param this_
 * @return Shape*
 */
Shape * Rectangle_getShape(Rectangle * const this_);

/**
 * @brief
 *
 * @param this_
 * @return Drawable*
 */
Drawable * Rectangle_getDrawable(Rectangle * const this_);

/**
 * @brief
 *
 * @param this_
 * @return uint32_t
 */
uint32_t Rectangle_getWidth(Rectangle const * const this_);

/**
 * @brief
 *
 * @param this_
 * @param width
 */
void Rectangle_setWidth(Rectangle * const this_, uint32_t const width);

/**
 * @brief
 *
 * @param this_
 * @return uint32_t
 */
uint32_t Rectangle_getHeight(Rectangle const * const this_);

/**
 * @brief
 *
 * @param this_
 * @param height
 */
void Rectangle_setHeight(Rectangle * const this_, uint32_t const height);

/**
 * @brief
 *
 * @param this_
 * @param edgeSize
 */
void Rectangle_makeSquare(Rectangle * const this_, uint32_t const edgeSize);

/**
 * @brief
 *
 */
typedef struct RectangleOperations {
    extends_(ObjectOperations);
    inherits_(ShapeOperations);
    inherits_(DrawableOperations);
} RectangleOperations;

/**
 * @brief
 *
 * @return RectangleOperations const*
 */
RectangleOperations const * RectangleOperations_(void);

/**
 * @brief
 *
 * @return Class const*
 */
Class const * RectangleClass_(void);

#endif // RECTANGLE_H
