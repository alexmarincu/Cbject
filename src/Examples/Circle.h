#ifndef CIRCLE_H
#define CIRCLE_H
#include "Cbject.h"
#include "Drawable.h"
#include "Shape.h"

class_(Circle);

/**
 * @brief CircleOps
 */
struct CircleOps {
    extend_(ObjectOps);
    inherit_(ShapeOps);
    inherit_(DrawableOps);
};

/**
 * @brief CircleClass
 */
struct CircleClass {
    extend_(ObjectClass);
    inherit_(ShapeInterface);
    inherit_(DrawableInterface);
};

/**
 * @brief Circle
 */
struct Circle {
    extend_(Object);
    inherit_(Shape);
    inherit_(Drawable);
    uint32_t radius;
};

/**
 * @brief Get CircleOps
 * @return CircleOps const*
 */
CircleOps const * CircleOps_(void);

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
