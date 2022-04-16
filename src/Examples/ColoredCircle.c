#include "ColoredCircle.h"
#include <stdio.h>

static void draw(Drawable const * const me);

ColoredCircleOps const * ColoredCircleOps_(void) {
    static ColoredCircleOps ops;

    doOnce_ {
        ops.xCircleOps = *CircleOps_();
        ops.xCircleOps.iDrawableOps.draw = draw;
    }

    return &ops;
}

ColoredCircleClass const * ColoredCircleClass_(void) {
    static ColoredCircleClass cls;

    doOnce_ {
        initClass_(&cls, ColoredCircle, CircleClass_());
        initInterface_(&to_(CircleClass, &cls)->iShapeInterface, offsetof(Circle, iShape), &((CircleOps *)ColoredCircleOps_())->iShapeOps);
        initInterface_(&to_(CircleClass, &cls)->iDrawableInterface, offsetof(Circle, iDrawable), &((CircleOps *)ColoredCircleOps_())->iDrawableOps);
    }

    return &cls;
}

ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color) {
    init_(Circle, me, origin, radius);

    initObject_(me, ColoredCircleClass_());
    initObject_(&((Circle *)me)->iShape, &((CircleClass *)ColoredCircleClass_())->iShapeInterface);
    initObject_(&((Circle *)me)->iDrawable, &((CircleClass *)ColoredCircleClass_())->iDrawableInterface);
    me->color = color;
    return me;
}

static void draw(Drawable const * const me) {
    ColoredCircle * Me = cast_(ColoredCircle, objectOf_(me));
    CircleOps_()->iDrawableOps.draw(me);
}
