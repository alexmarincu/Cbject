#ifndef SHAPE_H
#define SHAPE_H
#include "../cbject/cbject.h"
#include "Point.h"

typedef struct Shape Shape;
typedef struct ShapeClass ShapeClass;

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

/************************************************************************** @startuml(id=ShapeClass)
object ShapeClass {
    cbject_ObjectClass super;
    float (*area)(Shape const * const self);
}
@enduml *******************************************************************************************/
struct ShapeClass {
    cbject_ObjectClass super;
    float (*area)(Shape const * const self);
};

Shape * Shape_init(Shape * const self, Point origin);
float Shape_area(Shape const * const self);
ShapeClass * ShapeClass_instance(void);

#endif // SHAPE_H
