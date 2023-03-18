#include "Shape.h"

#define cbject_Class (Shape, cbject_Object)
cbject_utils_allocPool(0);

Shape * Shape_init(Shape * const shape, Point origin) {
    cbject_utils_init(shape);
    shape->origin = origin;
    return shape;
}

float Shape_area(Shape const * const shape) {
    return cbject_utils_invokeMethod(area, shape);
}

static float area(Shape const * const shape) {
    (void)shape;
    return 0;
}

ShapeClass * ShapeClass_instance(void) {
    static ShapeClass klass;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&klass);
        klass.area = area;
    }
    return &klass;
}

#undef cbject_Class
