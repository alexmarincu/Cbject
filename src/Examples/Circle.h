#ifndef CIRCLE_H
#define CIRCLE_H
#include "Cbject.h"
#include "Drawable.h"
#include "Shape.h"

/**
 * @brief
 */
typedef struct Circle {
    extends_(Object);
    inherits_(Shape);
    inherits_(Drawable);
    uint32_t radius;
} Circle;

/**
 * @brief
 * @param me
 * @param origin
 * @param radius
 * @return Circle*
 */
Circle * Circle_init(Circle * me, Point origin, uint32_t radius);

/**
 * @brief Contains Circle's ops (aka virtual functions)
 */
typedef struct CircleOps {
    extends_(ObjectOps);
    inherits_(ShapeOps);
    inherits_(DrawableOps);
} CircleOps;

/**
 * @brief
 * @return CircleOps const*
 */
CircleOps const * CircleOps_(void);

/**
 * @brief
 * @return Class const*
 */
Class const * CircleClass_(void);

#endif // CIRCLE_H
