#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"
typedef struct ShapeClass ShapeClass;
typedef struct Shape Shape;
/* @startuml(id=ShapeClass)
object ShapeClass {
    ObjectClass eObjectClass;
    float (*area)(Shape const * const shape);
}
@enduml */
struct ShapeClass {
    extends_(ObjectClass);
    float (*area)(Shape const * const shape);
};
/* @startuml(id=Shape)
object Shape {
    Object eObject;
    Point origin;
}
@enduml */
struct Shape {
    extends_(Object);
    Point origin;
};
ShapeClass const * ShapeClass_instance(void);
Shape * Shape_init(
    Shape * shape,
    Point origin
);
float Shape_area(Shape const * const shape);
#endif // SHAPE_H
