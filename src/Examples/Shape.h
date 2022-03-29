#ifndef SHAPE_H
#define SHAPE_H
#include "Cbject.h"
#include "Point.h"

/**
 * @brief
 *
 */
typedef struct Shape {
    interface_;
    Point origin;
} Shape;

/**
 * @brief
 *
 * @param this_
 * @return float
 */
float Shape_area(Shape const * const this_);
typedef float (*ShapeOperation_area)(Shape const * const this_);

/**
 * @brief
 *
 */
typedef struct ShapeOperations {
    ShapeOperation_area area;
} ShapeOperations;

/**
 * @brief
 *
 * @return ShapeOperations const*
 */
ShapeOperations const * ShapeOperations_(void);

#endif // SHAPE_H
