#ifndef SHAPE_H
#define SHAPE_H
#include "../cbject/cbject.h"
#include "Point.h"

typedef struct Shape Shape;
typedef struct Shape_Class Shape_Class;

/******************************************************************************* @startuml(id=Shape)
object Shape {
    cbject_Object super;
    Point origin;
}
@enduml *******************************************************************************************/
struct Shape {
    cbject_Object super;
    Point origin;
};

/************************************************************************** @startuml(id=Shape_Class)
object Shape_Class {
    cbject_Object_Class super;
    float (*area)(Shape const * const self);
}
@enduml *******************************************************************************************/
struct Shape_Class {
    cbject_Object_Class super;
    float (*area)(Shape const * const self);
};

Shape * Shape_init(Shape * const self, Point origin);
float Shape_area(Shape const * const self);
Shape_Class * Shape_Class_instance(void);

#endif // SHAPE_H
