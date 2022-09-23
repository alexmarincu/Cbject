#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Cbject/Cbject.h"
#include "Circle.h"
#include "Color.h"
/**
 * @brief ColoredCircle
 */
typedef struct {
    extends_(Circle);
    Color color;
} ColoredCircle;
/**
 * @brief ColoredCircle_Class
 */
typedef struct {
    extends_(Circle_Class);
} ColoredCircle_Class;
/**
 * @brief ColoredCircle_Class
 * @return ColoredCircle_Class const*
 */
ColoredCircle_Class const * ColoredCircle_Class_(void);
/**
 * @brief
 * @param me
 * @param origin
 * @param radius
 * @return ColoredCircle*
 */
ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color);
#endif // COLOREDCIRCLE_H
