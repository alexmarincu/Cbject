#include "ColoredCircle.h"
#include <stdio.h>
static void draw(Drawable const * const me);
ColoredCircle_Operations const * ColoredCircle_Operations_(void) {
    static ColoredCircle_Operations operations;
    doOnce_ {
        inheritOperations_(&operations, Circle);
        overrideIncludedOperation_(&operations, Circle, Drawable, draw);
    }
    return &operations;
}
ColoredCircle_Class const * ColoredCircle_Class_(void) {
    static ColoredCircle_Class cls;
    doOnce_ {
        initClass_(&cls, ColoredCircle, Circle);
        overrideIncludedInterface_(&cls, ColoredCircle, Circle, Shape);
        overrideIncludedInterface_(&cls, ColoredCircle, Circle, Drawable);
    }
    return &cls;
}
ColoredCircle * ColoredCircle_init(
    ColoredCircle * const me,
    Point const origin,
    uint32_t const radius,
    Color const color
) {
    init_(Circle, me, origin, radius);
    setClassOf_(me, ColoredCircle);
    overrideInterfaceObject_(me, ColoredCircle, Circle, Shape);
    overrideInterfaceObject_(me, ColoredCircle, Circle, Drawable);
    me->color = color;
    return me;
}
static void draw(Drawable const * const me) {
    ColoredCircle * Me = (ColoredCircle *)objectOf_(me);
    (void)Me;
    superIncludedCall_(Circle, Drawable, draw, me);
}
