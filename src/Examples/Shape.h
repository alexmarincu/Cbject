#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"

/**
 * @brief ShapeType
 */
typedef struct {
    extends_(Type);
} ShapeType;

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
 * @brief Calculate area of a shape
 * @param me Shape object reference
 * @return float Area of the shape
 */
float Shape_area(Shape const * const me);

#endif // SHAPE_H
