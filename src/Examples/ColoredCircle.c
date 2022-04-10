#include "ColoredCircle.h"
#include <stdio.h>

/**
 * @brief
 * @param me
 */
static void draw(Drawable const * const me) {
    ColoredCircle * _me = cast_(ColoredCircle, interfaceObjectOf_(me));
    superInterfaceCall_(Circle, Drawable, draw, _me);
}

/**
 * @brief
 * @param me
 * @param params
 */
ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color) {
    init_(Circle, me, origin, radius);
    initObject_(me, ColoredCircle);
    me->color = color;
    return me;
}

/**
 * @brief
 * @return ColoredCircleOperations const*
 */
ColoredCircleOperations const * ColoredCircleOperations_(void) {
    static ColoredCircleOperations operations;

    doOnce_({
        operations._xCircleOperations = *CircleOperations_();
        operations._xCircleOperations._iDrawableOperations.draw = draw;
    });

    return &operations;
}

/**
 * @brief
 * @return Class const*
 */
Class const * ColoredCircleClass_(void) {
    static Class class_;

    doOnce_({
        initClass_(&class_, ColoredCircle, Circle);
    });

    return &class_;
}
