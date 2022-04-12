#include "Shape.h"

/**
 *
 */
float Shape_area(Shape const * const me) {
    return interfaceCall_(Shape, area, me);
}
static float area(Shape const * const me) {
    assert_(false && "function not overriden");
    return 1;
}

/**
 *
 */
ShapeOps const * ShapeOps_(void) {
    static ShapeOps ops;

    doOnce_ {
        ops.area = area;
    }

    return &ops;
}
