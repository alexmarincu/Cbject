#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Cbject.h"
#include "Drawable.h"
#include "Shape.h"

class_(Rectangle);

/**
 * @brief RectangleOps
 */
struct RectangleOps {
    extend_(ObjectOps);
    inherit_(ShapeOps);
    inherit_(DrawableOps);
};

/**
 * @brief RectangleClass
 */
struct RectangleClass {
    extend_(ObjectClass);
    inherit_(ShapeInterface);
    inherit_(DrawableInterface);
};

/**
 * @brief Get RectangleOps
 * @return RectangleOps const*
 */
RectangleOps const * RectangleOps_(void);

/**
 * @brief Get RectangleClass
 * @return RectangleClass const*
 */
RectangleClass const * RectangleClass_(void);

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

#endif // RECTANGLE_H
