#include "Shape.h"
Shape_Interface const * Shape_Interface_(void) {
    static Shape_Interface interface;
    doOnce_ {
        initInterface_(Trait, &interface);
    };
    return &interface;
}
float Shape_area(Shape const * const me) {
    return traitMethodCall_(Shape, area, me);
}
Shape * Shape_init(
    Shape * me,
    Point origin
) {
    initTrait_(Trait, me);
    me->origin = origin;
    return me;
}
