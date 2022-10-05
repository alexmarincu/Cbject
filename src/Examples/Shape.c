#include "Shape.h"
static float area(Shape const * const shape);
ShapeClass const * ShapeClass_instance(void) {
    static ShapeClass class;
    return &class;
}
void ShapeClass_init(void) {
    setUpClass_(Shape, Object);
    bindClassMethod_(Shape, Shape, area);
}
Shape * Shape_init(
    Shape * shape,
    Point origin
) {
    setUpObject_(Shape, Object, shape);
    shape->origin = origin;
    return shape;
}
float Shape_area(Shape const * const shape) {
    return objectMethodCall_(Shape, area, shape);
}
static float area(Shape const * const shape) {
    ignore_(shape);
    return 0;
}
