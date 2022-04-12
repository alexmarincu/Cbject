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
ShapeOperations const * ShapeOperations_(void) {
    static ShapeOperations operations;

    doOnce_ {
        operations.area = area;
    }

    return &operations;
}
