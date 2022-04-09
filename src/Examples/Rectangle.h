#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Cbject.h"
#include "Drawable.h"
#include "Shape.h"

/**
 * @brief
 */
typedef struct Rectangle Rectangle;

/**
 * @brief
 * @param me
 * @param origin
 * @param width
 * @param height
 * @return Rectangle*
 */
Rectangle * Rectangle_init(Rectangle * me, Point origin, uint32_t width, uint32_t height);

/**
 * @brief
 * @param me
 * @return Shape*
 */
Shape * Rectangle_getShape(Rectangle * const me);

/**
 * @brief
 * @param me
 * @return Drawable*
 */
Drawable * Rectangle_getDrawable(Rectangle * const me);

/**
 * @brief
 * @param me
 * @return uint32_t
 */
uint32_t Rectangle_getWidth(Rectangle const * const me);

/**
 * @brief
 * @param me
 * @param width
 */
void Rectangle_setWidth(Rectangle * const me, uint32_t const width);

/**
 * @brief
 * @param me
 * @return uint32_t
 */
uint32_t Rectangle_getHeight(Rectangle const * const me);

/**
 * @brief
 * @param me
 * @param height
 */
void Rectangle_setHeight(Rectangle * const me, uint32_t const height);

/**
 * @brief
 * @param me
 * @param edgeSize
 */
void Rectangle_makeSquare(Rectangle * const me, uint32_t const edgeSize);

/**
 * @brief Contains Rectangle's operations (aka virtual functions)
 */
typedef struct RectangleOperations {
    extends_(ObjectOperations);
    inherits_(ShapeOperations);
    inherits_(DrawableOperations);
} RectangleOperations;

/**
 * @brief
 * @return RectangleOperations const*
 */
RectangleOperations const * RectangleOperations_(void);

/**
 * @brief
 * @return Class const*
 */
Class const * RectangleClass_(void);

#endif // RECTANGLE_H
