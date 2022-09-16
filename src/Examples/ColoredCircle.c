#include "ColoredCircle.h"
#include <stdio.h>
static void draw(Drawable const * const me);
ColoredCircle_Class const * ColoredCircle_Class_(void) {
    static ColoredCircle_Class cls;
    doOnce_ {
        initClass_(&cls, ColoredCircle, Circle);
        overrideInterface_(&cls, ColoredCircle, Circle, Shape);
        overrideInterface_(&cls, ColoredCircle, Circle, Drawable);
    }
    return &cls;
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
    overrideIObject_(me, ColoredCircle, Circle, Shape);
    overrideIObject_(me, ColoredCircle, Circle, Drawable);
    me->color = color;
    return me;
}
static void draw(Drawable const * const me) {
    ColoredCircle * Me = (ColoredCircle *)objectOf_(me);
    (void)Me;
    superICall_(Circle, Drawable, draw, me);
}
