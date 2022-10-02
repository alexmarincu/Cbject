#include "ColoredCircle.h"
#include <stdio.h>
static void draw(Drawable const * const drawable);
ColoredCircle_Class const * ColoredCircle_Class_(void) {
    static ColoredCircle_Class class;
    doOnce_({
        setUpClass_(ColoredCircle, Circle, &class);
        bindInterfaceMethod_(Circle, Drawable, &class, draw);
    });
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
