#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"
/**
 * @brief Shape_Interface
 */
typedef struct {
    extends_(Interface);
} Shape_Interface;
/**
 * @brief Shape
 */
typedef struct {
    extends_(Object);
    Point origin;
} Shape;
/**
 * @brief Shape_Operations
 */
typedef struct {
    float (*area)(Shape const * const me);
} Shape_Operations;
/**
 * @brief Calculate area of a shape
 * @param me Shape object reference
 * @return float Area of the shape
 */
float Shape_area(Shape const * const me);
#endif // SHAPE_H
