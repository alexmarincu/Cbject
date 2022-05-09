#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Cbject/Cbject.h"
#include "Circle.h"
#include "Color.h"

/**
 * @brief ColoredCircleClass
 */
typedef struct {
    extends_(CircleClass);
} ColoredCircleClass;

/**
 * @brief ColoredCircle
 */
typedef struct {
    extends_(Circle);
    Color color;
} ColoredCircle;

/**
 * @brief ColoredCircleInterface
 */
typedef struct {
    extends_(CircleInterface);
} ColoredCircleInterface;

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
