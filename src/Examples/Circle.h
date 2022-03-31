#ifndef CIRCLE_H
#define CIRCLE_H
#include "Cbject.h"
#include "Drawable.h"
#include "Shape.h"

/**
 * @brief
 *
 */
typedef struct Circle {
    extends_(Object);
    inherits_(Shape);
    inherits_(Drawable);
    uint32_t radius;
} Circle;

/**
 * @brief
 *
 * @param this_
 * @param origin
 * @param radius
 * @return Circle*
 */
Circle * Circle_init(Circle * this_, Point origin, uint32_t radius);

/**
 * @brief
 *
 * @param this_
 * @param degrees
 */
void Circle_rotate(Circle const * const this_, uint8_t const degrees);

/**
 * @brief
 *
 */
typedef struct CircleOperations {
    extends_(ObjectOperations);
    inherits_(ShapeOperations);
    inherits_(DrawableOperations);
} CircleOperations;

/**
 * @brief
 *
 * @return CircleOperations const*
 */
CircleOperations const * CircleOperations_(void);

/**
 * @brief
 *
 * @return Class const*
 */
Class const * CircleClass_(void);

#endif // CIRCLE_H
