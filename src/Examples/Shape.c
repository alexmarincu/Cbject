#include "Shape.h"

#define cbject_Class (Shape, cbject_Object)

Shape * Shape_init(Shape * const shape, Point origin) {
    cbject_Object_init((cbject_Object *)shape);
    shape->origin = origin;
    return shape;
}

float Shape_area(Shape const * const shape) {
    return cbject_invokeMethod(area, shape);
}

static float area(Shape const * const shape) {
    (void)shape;
    return 0;
}

ShapeClass const * ShapeClass_instance(void) {
    static ShapeClass klass;
    cbject_doOnce {
        cbject_Class_setup(&klass);
        klass.area = area;
    }
    return &klass;
}

#undef cbject_Class
