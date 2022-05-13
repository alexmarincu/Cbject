#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Cbject/Cbject.h"
#include "Drawable.h"
#include "Shape.h"

/**
 * @brief RectangleClass
 */
typedef struct {
    extends_(ObjectClass);
    contains_(ShapeType);
    contains_(DrawableType);
} RectangleClass;

typedef struct Rectangle Rectangle;

/**
 * @brief RectangleInterface
 */
typedef struct {
    extends_(ObjectInterface);
    contains_(ShapeInterface);
    contains_(DrawableInterface);
} RectangleInterface;

/**
 * @brief Get RectangleInterface
 * @return RectangleInterface const*
 */
RectangleInterface const * RectangleInterface_(void);

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
Rectangle * Rectangle_init(
    Rectangle * me,
    Point origin,
    uint32_t width,
    uint32_t height
);

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
