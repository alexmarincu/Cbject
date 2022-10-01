#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"
typedef struct Shape_Class Shape_Class;
typedef struct Shape Shape;
/* @startuml(id=Shape_Class)
object Shape_Class {
    Object_Class super;
    float (*area)(Shape const * const shape);
}
@enduml */
struct Shape_Class {
    extends_(Object_Class);
    float (*area)(Shape const * const shape);
};
/* @startuml(id=Shape)
object Shape {
    Object super;
    Point origin;
}
@enduml */
struct Shape {
    extends_(Object);
    Point origin;
};
Shape_Class const * Shape_Class_(void);
Shape * Shape_init(
    Shape * shape,
    Point origin
);
float Shape_area(Shape const * const shape);
#endif // SHAPE_H
