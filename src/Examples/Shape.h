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

float Shape_area(Shape const * const me);

/**
 * @brief Contains Shape's operations (aka virtual functions)
 */
typedef struct ShapeOperations {
    float (*area)(Shape const * const me);
} ShapeOperations;

ShapeOperations const * ShapeOperations_(void);

#endif // SHAPE_H
