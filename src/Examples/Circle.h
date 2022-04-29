#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Cbject/Cbject.h"
#include "Drawable.h"
#include "Shape.h"

/**
 * @brief CircleClass
 */
typedef struct {
    super_(ObjectClass);
    mixin_(ShapeMixin);
    mixin_(DrawableMixin);
} CircleClass;

/**
 * @brief Circle
 */
typedef struct {
    super_(Object);
    mixin_(Shape);
    mixin_(Drawable);
    uint32_t radius;
} Circle;

/**
 * @brief CircleInterface
 */
typedef struct {
    super_(ObjectInterface);
    mixin_(ShapeInterface);
    mixin_(DrawableInterface);
} CircleInterface;

/**
 * @brief Get CircleInterface
 * @return CircleInterface const*
 */
CircleInterface const * CircleInterface_(void);

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
