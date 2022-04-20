#include "ColoredCircle.h"
#include <stdio.h>

static void draw(Drawable const * const me);

ColoredCircleInterface const * ColoredCircleInterface_(void) {
    static ColoredCircleInterface interface;

    doOnce_ {
        inheritInterface_(&interface, Circle);
        overrideMixinOperation_(&interface, Circle, Drawable, draw);
    }

    return &interface;
}

ColoredCircleClass const * ColoredCircleClass_(void) {
    static ColoredCircleClass cls;

    doOnce_ {
        initClass_(&cls, ColoredCircle, Circle);
        overrideMixin_(&cls, ColoredCircle, Circle, Shape);
        overrideMixin_(&cls, ColoredCircle, Circle, Drawable);
    }

    return &cls;
}

ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color) {
    init_(Circle, me, origin, radius);
    overrideObject_(me, ColoredCircle);
    overrideMixinObject_(me, ColoredCircle, Circle, Shape);
    overrideMixinObject_(me, ColoredCircle, Circle, Drawable);
    me->color = color;
    return me;
}

static void draw(Drawable const * const me) {
    ColoredCircle * Me = to_(ColoredCircle, objectOf_(me));
    superMixinCall_(Circle, Drawable, draw, me);
}
