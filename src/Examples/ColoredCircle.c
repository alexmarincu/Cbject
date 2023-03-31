#include "ColoredCircle.h"

#define cbject_Class (ColoredCircle, Circle)
cbject_noPool;

ColoredCircle * ColoredCircle_init(
    ColoredCircle * const self,
    Point const origin,
    uint32_t const radius,
    Color const color
) {
    Circle_init((Circle *)self, origin, radius);
    self->color = color;
    return self;
}

static void draw(Drawable const * const self) {
    cbject_invokeSuperMethod(Drawable, draw, self);
}

ColoredCircle_Class * ColoredCircle_Class_instance(void) {
    static ColoredCircle_Class self;
    cbject_doOnce {
        cbject_Class_setup(&self);
        ((Drawable_Class *)&self)->draw = draw;
    }
    return &self;
}

#undef cbject_Class
