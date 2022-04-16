#ifndef SHAPE_H
#define SHAPE_H
#include "Cbject.h"
#include "Point.h"

interface_(Shape);

/**
 * @brief ShapeOps
 */
struct ShapeOps {
    float (*area)(Shape const * const me);
};

/**
 * @brief ShapeInterface
 */
struct ShapeInterface {
    extend_(Interface);
};

/**
 * @brief Shape
 */
struct Shape {
    extend_(Object);
    Point origin;
};

/**
 * @brief Calculates area of a shape
 * @param me The shape object
 * @return float The area of the shape
 */
float Shape_area(Shape const * const me);

#endif // SHAPE_H
