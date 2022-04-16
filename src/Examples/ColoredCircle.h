#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Cbject.h"
#include "Circle.h"
#include "Color.h"

class_(ColoredCircle);

/**
 * @brief ColoredCircleOperations
 */
struct ColoredCircleOperations {
    extend_(CircleOperations);
};

/**
 * @brief ColoredCircleClass
 */
struct ColoredCircleClass {
    extend_(CircleClass);
};

/**
 * @brief ColoredCircle
 */
struct ColoredCircle {
    extend_(Circle);
    Color color;
};

/**
 * @brief ColoredCircleOperations
 * @return ColoredCircleOperations const*
 */
ColoredCircleOperations const * ColoredCircleOperations_(void);

/**
 * @brief ColoredCircleClass
 * @return ColoredCircleClass const*
 */
ColoredCircleClass const * ColoredCircleClass_(void);

/**
 * @brief
 * @param me
 * @param origin
 * @param radius
 * @return ColoredCircle*
 */
ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color);

#endif // COLOREDCIRCLE_H
