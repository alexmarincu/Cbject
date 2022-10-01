#include "ColoredCircle.h"
#include <stdio.h>
static void draw(Drawable const * const me);
ColoredCircle_Class const * ColoredCircle_Class_(void) {
    static ColoredCircle_Class class;
    doOnce_ {
        setUpClass_(ColoredCircle, Circle, &class);
        overrideInterfaceMethod_(Circle, Drawable, &class, draw);
    }
    return &class;
}
ColoredCircle * ColoredCircle_init(
    ColoredCircle * const me,
    Point const origin,
    uint32_t const radius,
    Color const color
) {
    setUpObject_(ColoredCircle, Circle, me, origin, radius);
    me->color = color;
    return me;
}
static void draw(Drawable const * const me) {
    ColoredCircle * Me = to_(ColoredCircle, objectOf_(me));
    ignore_(Me);
    interfaceMethodCall_(Circle, Drawable, draw, me);
}
