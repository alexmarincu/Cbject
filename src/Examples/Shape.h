#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"

/**
 * @brief ShapeMixin
 */
typedef struct {
    super_(ObjectMixin);
} ShapeMixin;

/**
 * @brief Shape
 */
typedef struct {
    super_(Object);
    Point origin;
} Shape;

/**
 * @brief ShapeInterface
 */
typedef struct {
    float (*area)(Shape const * const me);
} ShapeInterface;

/**
 * @brief Calculates area of a shape
 * @param me The shape object
 * @return float The area of the shape
 */
float Shape_area(Shape const * const me);

#endif // SHAPE_H
