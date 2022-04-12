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
 * @brief Contains Shape's ops (aka virtual functions)
 */
typedef struct ShapeOps {
    float (*area)(Shape const * const me);
} ShapeOps;

/**
 * @brief Gets reference to ShapeOps
 * @remark At first call the initialization is done
 * @return ShapeOps const* The reference to ShapeOps
 */
ShapeOps const * ShapeOps_(void);

#endif // SHAPE_H
