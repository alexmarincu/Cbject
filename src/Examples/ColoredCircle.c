#include "ColoredCircle.h"

#define cbject_Class (ColoredCircle, Circle)
static ColoredCircle ColoredCircle_pool[10];

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

ColoredCircleClass const * ColoredCircleClass_instance(void) {
    static ColoredCircleClass klass;
    cbject_doOnce {
        cbject_Class_setup(&klass);
        klass.circleClass.drawableClass.draw = draw;
    }
    return &klass;
}

#undef cbject_Class
