#include "ColoredCircle.h"
#include <stdio.h>
static void draw(Drawable const * const me);
ColoredCircle_Class const * ColoredCircle_Class_(void) {
    static ColoredCircle_Class class;
    doOnce_ {
        initClass_(&class, ColoredCircle, Circle);
        initInterfaceOf_(&class, ColoredCircle, Circle, Shape);
        initInterfaceOf_(&class, ColoredCircle, Circle, Drawable);
    }
    return &class;
}
ColoredCircle_Operations const * ColoredCircle_Operations_(void) {
    static ColoredCircle_Operations operations;
    doOnce_ {
        inheritOperations_(&operations, Circle);
        overrideIOperation_(&operations, Circle, Drawable, draw);
    }
    return &operations;
}
ColoredCircle * ColoredCircle_init(
    ColoredCircle * const me,
    Point const origin,
    uint32_t const radius,
    Color const color
) {
    init_(Circle, me, origin, radius);
    setClassOf_(me, ColoredCircle);
    initIObjectOf_(me, ColoredCircle, Circle, Shape);
    initIObjectOf_(me, ColoredCircle, Circle, Drawable);
    me->color = color;
    return me;
}
static void draw(Drawable const * const me) {
    ColoredCircle * Me = (ColoredCircle *)rObjectOf_(me);
    (void)Me;
    superICall_(Circle, Drawable, draw, me);
}
