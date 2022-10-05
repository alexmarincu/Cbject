#include "ColoredCircle.h"
#include <stdio.h>
static void draw(Drawable const * const drawable);
ColoredCircleClass const * ColoredCircleClass_instance(void) {
    static ColoredCircleClass class;
    doOnce_ {
        setUpClass_(ColoredCircle, Circle, &class);
        bindInterfaceMethodOf_(Circle, Drawable, draw, &class);
    }
    return &class;
}
ColoredCircle * ColoredCircle_init(
    ColoredCircle * const coloredCircle,
    Point const origin,
    uint32_t const radius,
    Color const color
) {
    setUpObject_(ColoredCircle, Circle, coloredCircle, origin, radius);
    coloredCircle->color = color;
    return coloredCircle;
}
static void draw(Drawable const * const drawable) {
    interfaceMethodCall_(Circle, Drawable, draw, drawable);
}
