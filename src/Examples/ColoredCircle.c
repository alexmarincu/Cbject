#include "ColoredCircle.h"

#define cbject_Class (ColoredCircle, Circle)
cbject_allocPool(0);

ColoredCircle * ColoredCircle_init(
    ColoredCircle * const coloredCircle,
    Point const origin,
    uint32_t const radius,
    Color const color
) {
    Circle_init((Circle *)coloredCircle, origin, radius);
    coloredCircle->color = color;
    return coloredCircle;
}

static void draw(Drawable const * const drawable) {
    cbject_invokeSuperMethod(Drawable, draw, drawable);
}

ColoredCircleClass * ColoredCircleClass_instance(void) {
    static ColoredCircleClass klass;
    cbject_doOnce {
        cbject_Class_setup(&klass);
        klass.circleClass.drawableClass.draw = draw;
    }
    return &klass;
}

#undef cbject_Class
