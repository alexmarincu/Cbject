#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"
typedef struct Shape_Class Shape_Class;
typedef struct Shape Shape;
struct Shape_Class {
    extends_(Object_Class);
    float (*area)(Shape const * const me);
};
struct Shape {
    extends_(Object);
    Point origin;
};
Shape_Class const * Shape_Class_(void);
Shape * Shape_init(
    Shape * me,
    Point origin
);
float Shape_area(Shape const * const me);
#endif // SHAPE_H
