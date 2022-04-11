#include "ColoredCircle.h"
#include <stdio.h>

/**
 * @brief
 * @param me
 */
static void draw(Drawable const * const me) {
    ColoredCircle * Me = cast_(ColoredCircle, objectOf_(me));
    CircleOperations_()->iDrawableOperations.draw(&Me->xCircle.iDrawable);
}

/**
 * @brief
 * @param me
 * @param params
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
 * @brief
 * @return ColoredCircleOperations const*
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
 * @brief
 * @return Class const*
 */
Class const * ColoredCircleClass_(void) {
    static Class class_;

    doOnce_ {
        initClass_(&class_, ColoredCircle, Circle);
    }

    return &class_;
}
