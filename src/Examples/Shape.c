#include "Shape.h"
static float area(Shape const * const shape);
ShapeClass const * ShapeClass_instance(void) {
    static ShapeClass shapeClass;
    x_doOnce {
        x_setUpClass(Shape, x_Object, &shapeClass);
        x_bindClassMethod(Shape, area, &shapeClass);
    }
    return &shapeClass;
}
Shape * Shape_init(Shape * const shape, Point origin) {
    x_setUpObject(Shape, x_Object, shape);
    shape->origin = origin;
    return shape;
}
float Shape_area(Shape const * const shape) {
    return x_callObjectMethod(Shape, area, shape);
}
static float area(Shape const * const shape) {
    x_ignore(shape);
    return 0;
}
