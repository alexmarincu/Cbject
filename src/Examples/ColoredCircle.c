#include "ColoredCircle.h"
#include <stdio.h>

/**
 *
 */
static void draw(Drawable const * const me) {
    ColoredCircle * Me = cast_(ColoredCircle, objectOf_(me));
    CircleOperations_()->iDrawableOperations.draw(&Me->xCircle.iDrawable);
}

/**
 *
 */
ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color) {
    init_(Circle, me, origin, radius);
    initObject_(me, ColoredCircle);
    initInterface_(&me->xCircle.iShape, me, &ColoredCircleOperations_()->xCircleOperations.iShapeOperations);
    initInterface_(&me->xCircle.iDrawable, me, &ColoredCircleOperations_()->xCircleOperations.iDrawableOperations);
    me->color = color;
    return me;
}

/**
 *
 */
ColoredCircleOperations const * ColoredCircleOperations_(void) {
    static ColoredCircleOperations operations;

    doOnce_ {
        operations.xCircleOperations = *CircleOperations_();
        operations.xCircleOperations.iDrawableOperations.draw = draw;
    }

    return &operations;
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
