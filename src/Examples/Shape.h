#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"
/**
 * @brief Shape
 */
typedef struct {
    extends_(Trait);
    Point origin;
} Shape;
/**
 * @brief Shape_Interface
 */
typedef struct {
    extends_(Trait_Interface);
    float (*area)(Shape const * const me);
} Shape_Interface;
/**
 * @brief Shape_Interface
 * @return Shape_Interface const*
 */
Shape_Interface const * Shape_Interface_(void);
/**
 * @brief Calculate area of a shape
 * @param me Shape object reference
 * @return float Area of the shape
 */
float Shape_area(Shape const * const me);
/**
 * @brief
 * @param me
 * @param origin
 * @param width
 * @param height
 * @return Rectangle*
 */
Shape * Shape_init(
    Shape * me,
    Point origin
);
#endif // SHAPE_H
