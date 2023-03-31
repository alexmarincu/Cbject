#include "Shape.h"

#define cbject_Class (Shape, cbject_Object)
cbject_noPool;

Shape * Shape_init(Shape * const self, Point origin) {
    cbject_init(self);
    self->origin = origin;
    return self;
}

float Shape_area(Shape const * const self) {
    return cbject_invokeMethod(area, self);
}

static float area(Shape const * const self) {
    (void)self;
    return 0;
}

ShapeClass * ShapeClass_instance(void) {
    static ShapeClass self;
    cbject_doOnce {
        cbject_ObjectClass_setup(&self);
        self.area = area;
    }
    return &self;
}

#undef cbject_Class
