#include "ColoredCircle.h"
#include <stdio.h>
static void draw(Drawable const * const drawable);
ColoredCircleClass const * ColoredCircleClass_instance(void) {
    static ColoredCircleClass coloredCircleClass;
    x_doOnce {
        x_setUpClass(ColoredCircle, Circle, &coloredCircleClass);
        x_bindInterfaceMethodOf(Circle, Drawable, draw, &coloredCircleClass);
    }
    return &coloredCircleClass;
}
ColoredCircle * ColoredCircle_init(
    ColoredCircle * const coloredCircle,
    Point const origin,
    uint32_t const radius,
    Color const color
) {
    x_setUpObject(ColoredCircle, Circle, coloredCircle, origin, radius);
    coloredCircle->color = color;
    return coloredCircle;
}
static void draw(Drawable const * const drawable) {
    x_callInterfaceMethod(Circle, Drawable, draw, drawable);
}
