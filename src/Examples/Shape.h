#ifndef SHAPE_H
#define SHAPE_H
#include "../cbject/cbject.h"
#include "Point.h"

typedef struct Shape Shape;
typedef struct ShapeClass ShapeClass;

/************************************************* @startuml(id=Shape)
object Shape {
    cbject_Object object;
    Point origin;
}
@enduml *************************************************/
struct Shape {
    cbject_Object object;
    Point origin;
};

/************************************************* @startuml(id=ShapeClass)
object ShapeClass {
    cbject_ObjectClass objectClass;
    float (*area)(Shape const * const shape);
}
@enduml *************************************************/
struct ShapeClass {
    cbject_ObjectClass objectClass;
    float (*area)(Shape const * const shape);
};

Shape * Shape_init(Shape * const shape, Point origin);
float Shape_area(Shape const * const shape);
ShapeClass const * ShapeClass_instance(void);

#endif // SHAPE_H
