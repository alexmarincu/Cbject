#include "Shape.h"
#include "cbject_Object.h"
static float area(Shape const * const shape);
ShapeClass const * ShapeClass_getInstance(void) {
    static ShapeClass shapeClass;
    cbject_doOnce {
        cbject_setUpClass(Shape, cbject_Object, &shapeClass);
        cbject_bindClassMethod(Shape, area, &shapeClass);
    }
    return &shapeClass;
}
Shape * Shape_init(Shape * const shape, Point origin) {
    cbject_Object_init((cbject_Object *)shape);
    shape->origin = origin;
    return shape;
}
float Shape_area(Shape const * const shape) {
    return cbject_callMethodOfObject(Shape, area, shape);
}
static float area(Shape const * const shape) {
    (void)shape;
    return 0;
}
