#include "ColoredCircle.h"
#include "Circle.h"
#include <stdio.h>
static void draw(Drawable const * const drawable);
ColoredCircleClass const * ColoredCircleClass_getInstance(void) {
    static ColoredCircleClass coloredCircleClass;
    cbject_doOnce {
        cbject_setUpClass(ColoredCircle, Circle, &coloredCircleClass);
        cbject_bindInterfaceMethodOf(Circle, Drawable, draw, &coloredCircleClass);
    }
    return &coloredCircleClass;
}
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
    cbject_callMethodOfInterface(Circle, Drawable, draw, drawable);
}
