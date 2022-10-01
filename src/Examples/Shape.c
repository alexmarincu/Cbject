#include "Shape.h"
static float area(Shape const * const me);
Shape_Class const * Shape_Class_(void) {
    static Shape_Class class;
    doOnce_ {
        setUpClass_(Shape, Object, &class);
        overrideObjectMethod_(Shape, &class, area);
    };
    return &class;
}
Shape * Shape_init(
    Shape * me,
    Point origin
) {
    setUpObject_(Shape, Object, me);
    me->origin = origin;
    return me;
}
float Shape_area(Shape const * const me) {
    return objectMethodCall_(Shape, area, me);
}
static float area(Shape const * const me) {
    ignore_(me);
    return 0;
}
