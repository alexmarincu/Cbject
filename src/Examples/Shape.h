#ifndef SHAPE_H
#define SHAPE_H
#include "Cbject.h"
#include "Point.h"

defineMixin_(Shape);

/**
 * @brief ShapeInterface
 */
struct ShapeInterface {
    float (*area)(Shape const * const me);
};

/**
 * @brief ShapeMixin
 */
struct ShapeMixin {
    super_(Mixin);
};

/**
 * @brief Shape
 */
struct Shape {
    super_(Object);
    Point origin;
};

/**
 * @brief Calculates area of a shape
 * @param me The shape object
 * @return float The area of the shape
 */
float Shape_area(Shape const * const me);

#endif // SHAPE_H
