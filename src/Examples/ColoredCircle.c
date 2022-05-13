#include "ColoredCircle.h"
#include <stdio.h>

static void draw(Drawable const * const me);

ColoredCircleInterface const * ColoredCircleInterface_(void) {
    static ColoredCircleInterface interface;

    doOnce_ {
        inheritInterface_(&interface, Circle);
        overrideNestedOperation_(&interface, Circle, Drawable, draw);
    }

    return &interface;
}

ColoredCircleClass const * ColoredCircleClass_(void) {
    static ColoredCircleClass cls;

    doOnce_ {
        initClass_(&cls, ColoredCircle, Circle);
        overrideNestedType_(&cls, ColoredCircle, Circle, Shape);
        overrideNestedType_(&cls, ColoredCircle, Circle, Drawable);
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
    overrideObject_(me, ColoredCircle);
    overrideNestedObject_(me, ColoredCircle, Circle, Shape);
    overrideNestedObject_(me, ColoredCircle, Circle, Drawable);
    me->color = color;
    return me;
}

static void draw(Drawable const * const me) {
    ColoredCircle * Me = to_(ColoredCircle, parentObjectOf_(me));
    superNestedCall_(Circle, Drawable, draw, me);
}
