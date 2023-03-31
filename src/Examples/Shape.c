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

Shape_Class * Shape_Class_instance(void) {
    static Shape_Class self;
    cbject_doOnce {
        cbject_Object_Class_setup(&self);
        self.area = area;
    }
    return &self;
}

#undef cbject_Class
