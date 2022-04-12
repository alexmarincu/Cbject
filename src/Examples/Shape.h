#ifndef SHAPE_H
#define SHAPE_H
#include "Cbject.h"
#include "Point.h"

/**
 * @brief interface Shape
 */
typedef struct Shape {
    extends_(Interface);
    Point origin;
} Shape;

/**
 * @brief Calculates area of a shape
 * @param me The shape's interface
 * @return float The area of the shape
 */
float Shape_area(Shape const * const me);

/**
 * @brief Contains Shape's operations (aka virtual functions)
 */
typedef struct ShapeOperations {
    float (*area)(Shape const * const me);
} ShapeOperations;

/**
 * @brief Gets reference to ShapeOperations
 * @remark At first call the initialization is done
 * @return ShapeOperations const* The reference to ShapeOperations
 */
ShapeOperations const * ShapeOperations_(void);

#endif // SHAPE_H
