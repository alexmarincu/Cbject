#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "Cbject.h"
#include "Circle.h"
#include "Color.h"

/**
 * @brief
 */
typedef struct ColoredCircle {
    extends_(Circle);
    Color color;
} ColoredCircle;

/**
 * @brief
 * @param me
 * @param origin
 * @param radius
 * @return ColoredCircle*
 */
ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color);

/**
 * @brief Contains ColoredCircle's ops (aka virtual functions)
 */
typedef struct ColoredCircleOps {
    extends_(CircleOps);
} ColoredCircleOps;

/**
 * @brief
 * @return ColoredCircleOps const*
 */
ColoredCircleOps const * ColoredCircleOps_(void);

/**
 * @brief
 * @return Class const*
 */
Class const * ColoredCircleClass_(void);

#endif // COLOREDCIRCLE_H
