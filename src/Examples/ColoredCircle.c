#include "ColoredCircle.h"
#include <stdio.h>

/**
 *
 */
static void draw(Drawable const * const me) {
    ColoredCircle * Me = cast_(ColoredCircle, objectOf_(me));
    CircleOps_()->iDrawableOps.draw(me);
}

/**
 *
 */
ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color) {
    init_(Circle, me, origin, radius);
    objectOf_(me)->cls = ColoredCircleClass_();
    me->xCircle.iShape.xInterface.ops =
        initInterface_(&me->xCircle.iShape, offsetof(Circle, iShape), &ColoredCircleOps_()->xCircleOps.iShapeOps);
    initInterface_(&me->xCircle.iDrawable, offsetof(Circle, iDrawable), &ColoredCircleOps_()->xCircleOps.iDrawableOps);
    me->color = color;
    return me;
}

/**
 *
 */
ColoredCircleOps const * ColoredCircleOps_(void) {
    static ColoredCircleOps ops;

    doOnce_ {
        ops.xCircleOps = *CircleOps_();
        ops.xCircleOps.iDrawableOps.draw = draw;
    }

    return &ops;
}

/**
 *
 */
Class const * ColoredCircleClass_(void) {
    static Class cls;

    doOnce_ {
        initClass_(&cls, ColoredCircle, Circle);
    }

    return &cls;
}
