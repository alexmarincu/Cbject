#include "ColoredCircle.h"
#include <stdio.h>

static void draw(Drawable const * const me);

ColoredCircleInterface const * ColoredCircleInterface_(void) {
    static ColoredCircleInterface interface;

    doOnce_ {
        inheritInterface_(&interface, Circle);
        overrideOperationIn_(&interface, Circle, Drawable, draw);
    }

    return &interface;
}

ColoredCircleClass const * ColoredCircleClass_(void) {
    static ColoredCircleClass cls;

    doOnce_ {
        initClass_(&cls, ColoredCircle, Circle);
        overrideTraitIn_(&cls, ColoredCircle, Circle, Shape);
        overrideTraitIn_(&cls, ColoredCircle, Circle, Drawable);
    }

    return &cls;
}

ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color) {
    init_(Circle, me, origin, radius);
    overrideObject_(me, ColoredCircle);
    overrideObjectIn_(me, ColoredCircle, Circle, Shape);
    overrideObjectIn_(me, ColoredCircle, Circle, Drawable);
    me->color = color;
    return me;
}

static void draw(Drawable const * const me) {
    ColoredCircle * Me = to_(ColoredCircle, objectOf_(me));
    superTraitCall_(Circle, Drawable, draw, me);
}
