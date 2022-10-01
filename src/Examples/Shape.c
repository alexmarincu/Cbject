#include "Shape.h"
static float area(Shape const * const shape);
Shape_Class const * Shape_Class_(void) {
    static Shape_Class class;
    doOnce_ {
        setUpClass_(Shape, Object, &class);
        overrideClassMethod_(Shape, &class, area);
    };
    return &class;
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
