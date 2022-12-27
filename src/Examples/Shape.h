#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"
x_typedefClass(Shape);
/* @startuml(id=ShapeClass)
object ShapeClass {
    x_ObjectClass exObjectClass;
    float (*area)(Shape const * const shape);
}
@enduml */
struct ShapeClass {
    x_extends(x_ObjectClass);
    float (*area)(Shape const * const shape);
};
/* @startuml(id=Shape)
object Shape {
    x_Object exObject;
    Point origin;
}
@enduml */
struct Shape {
    x_extends(x_Object);
    Point origin;
};
ShapeClass const * ShapeClass_instance(void);
Shape * Shape_init(Shape * const shape, Point origin);
float Shape_area(Shape const * const shape);
#endif // SHAPE_H
