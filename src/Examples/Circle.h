#ifndef CIRCLE_H
#define CIRCLE_H
#include "Cbject.h"
#include "Drawable.h"
#include "Shape.h"

class_(Circle);

/**
 * @brief CircleOperations
 */
struct CircleOperations {
    extend_(ObjectOperations);
    implement_(ShapeOperations);
    implement_(DrawableOperations);
};

/**
 * @brief CircleClass
 */
struct CircleClass {
    extend_(ObjectClass);
    implement_(ShapeInterface);
    implement_(DrawableInterface);
};

/**
 * @brief Circle
 */
struct Circle {
    extend_(Object);
    implement_(Shape);
    implement_(Drawable);
    uint32_t radius;
};

/**
 * @brief Get CircleOperations
 * @return CircleOperations const*
 */
CircleOperations const * CircleOperations_(void);

/**
 * @brief Get CircleClass
 * @return Class const*
 */
CircleClass const * CircleClass_(void);

/**
 * @brief Init Circle object
 * @param me
 * @param origin
 * @param radius
 * @return Circle*
 */
Circle * Circle_init(Circle * me, Point origin, uint32_t radius);

#endif // CIRCLE_H
