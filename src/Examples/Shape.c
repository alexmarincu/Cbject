#include "Shape.h"
Shape_Interface const * Shape_Interface_(void) {
    static Shape_Interface interface;
    doOnce_ {
        initInterface_(Module, &interface);
    };
    return &interface;
}
float Shape_area(Shape const * const me) {
    return moduleMethodCall_(Shape, area, me);
}
Shape * Shape_init(
    Shape * me,
    Point origin
) {
    initModule_(Module, me);
    me->origin = origin;
    return me;
}
