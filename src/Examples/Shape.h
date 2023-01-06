#ifndef SHAPE_H
#define SHAPE_H
#include "../cbject/cbject.h"
#include "Point.h"
cbject_typedefClass(Shape);
/* @startuml(id=ShapeClass)
object ShapeClass {
    cbject_ObjectClass s_cbject_ObjectClass;
    float (*area)(Shape const * const shape);
}
@enduml */
struct ShapeClass {
    cbject_is(cbject_ObjectClass);
    float (*area)(Shape const * const shape);
};
/* @startuml(id=Shape)
object Shape {
    cbject_Object s_cbject_Object;
    Point origin;
}
@enduml */
struct Shape {
    cbject_is(cbject_Object);
    Point origin;
};
ShapeClass const * ShapeClass_getInstance(void);
Shape * Shape_init(Shape * const shape, Point origin);
float Shape_area(Shape const * const shape);
#endif // SHAPE_H
