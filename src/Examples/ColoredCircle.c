#include "ColoredCircle.h"
#include <stdio.h>

static void draw(Drawable const * const me);

ColoredCircleOperations const * ColoredCircleOperations_(void) {
    static ColoredCircleOperations operations;

    doOnce_ {
        inheritOperationsOf_(Circle, &operations);
        overrideInterfaceOperation_(Circle, Drawable, draw, &operations);
    }

    return &operations;
}

ColoredCircleClass const * ColoredCircleClass_(void) {
    static ColoredCircleClass cls;

    doOnce_ {
        initClass_(&cls, ColoredCircle, Circle);
        initChildInterface_(&cls, ColoredCircle, Circle, Shape);
        initChildInterface_(&cls, ColoredCircle, Circle, Drawable);
    }

    return &cls;
}

ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color) {
    init_(Circle, me, origin, radius);
    initObject_(me, ColoredCircle);
    initChildObject_(me, ColoredCircle, Circle, Shape);
    initChildObject_(me, ColoredCircle, Circle, Drawable);
    me->color = color;
    return me;
}

static void draw(Drawable const * const me) {
    ColoredCircle * Me = to_(ColoredCircle, objectOf_(me));
    CircleOperations_()->iDrawableOperations.draw(me);
}
