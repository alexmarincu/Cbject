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

ColoredCircleClass * ColoredCircleClass_instance(void) {
    static ColoredCircleClass self;
    cbject_doOnce {
        cbject_ObjectClass_setup(&self);
        ((DrawableClass *)&self)->draw = draw;
    }
    return &self;
}

#undef cbject_Class
