#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Cbject.h"
#include "Circle.h"
#include "Color.h"

defClass_(ColoredCircle);

/**
 * @brief ColoredCircleInterface
 */
struct ColoredCircleInterface {
    super_(CircleInterface);
};

/**
 * @brief ColoredCircleClass
 */
struct ColoredCircleClass {
    super_(CircleClass);
};

/**
 * @brief ColoredCircle
 */
struct ColoredCircle {
    super_(Circle);
    Color color;
};

/**
 * @brief ColoredCircleInterface
 * @return ColoredCircleInterface const*
 */
ColoredCircleInterface const * ColoredCircleInterface_(void);

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
