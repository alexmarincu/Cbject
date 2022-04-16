#include "ColoredCircle.h"
#include <stdio.h>

static void draw(Drawable const * const me);

ColoredCircleOperations const * ColoredCircleOperations_(void) {
    static ColoredCircleOperations operations;

    doOnce_ {
        operations.xCircleOperations = *CircleOperations_();
        operations.xCircleOperations.iDrawableOperations.draw = draw;
    }

    return &operations;
}

ColoredCircleClass const * ColoredCircleClass_(void) {
    static ColoredCircleClass cls;

    doOnce_ {
        initClass_(&cls, ColoredCircle, CircleClass_());
        initInterface_(&to_(CircleClass, &cls)->iShapeInterface, offsetof(Circle, iShape), &to_(CircleOperations, ColoredCircleOperations_())->iShapeOperations);
        initInterface_(&to_(CircleClass, &cls)->iDrawableInterface, offsetof(Circle, iDrawable), &to_(CircleOperations, ColoredCircleOperations_())->iDrawableOperations);
    }

    return &cls;
}

ColoredCircle * ColoredCircle_init(ColoredCircle * const me, Point const origin, uint32_t const radius, Color const color) {
    init_(Circle, me, origin, radius);
    initObject_(me, ColoredCircleClass_());
    initObject_(&to_(Circle, me)->iShape, &to_(CircleClass, ColoredCircleClass_())->iShapeInterface);
    initObject_(&to_(Circle, me)->iDrawable, &to_(CircleClass, ColoredCircleClass_())->iDrawableInterface);
    me->color = color;
    return me;
}

static void draw(Drawable const * const me) {
    ColoredCircle * Me = to_(ColoredCircle, objectOf_(me));
    CircleOperations_()->iDrawableOperations.draw(me);
}
