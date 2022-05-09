#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"

/**
 * @brief ShapeTrait
 */
typedef struct {
    extends_(ObjectTrait);
} ShapeTrait;

/**
 * @brief Shape
 */
typedef struct {
    extends_(Object);
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
