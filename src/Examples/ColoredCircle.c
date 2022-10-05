#include "ColoredCircle.h"
#include <stdio.h>
static void draw(Drawable const * const drawable);
ColoredCircleClass const * ColoredCircleClass_instance(void) {
    static ColoredCircleClass class;
    return &class;
}
void ColoredCircleClass_init(void) {
    setUpClass_(ColoredCircle, Circle);
    bindInterfaceMethodOf_(ColoredCircle, Circle, Drawable, draw);
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
