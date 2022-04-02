#include "Shape.h"

/**
 * @brief
 *
 * @param this_
 * @return float
 */
float Shape_area(Shape const * const this_) {
    return interfaceCall_(Shape, area, this_);
}
static float area(Shape const * const this_) {
    assert_(false && "function not overriden");
    return 1;
}

/**
 * @brief
 *
 * @return ShapeOperations const*
 */
ShapeOperations const * ShapeOperations_(void) {
    static ShapeOperations operations;

    doOnce_({
        operations.area = area;
    });

    return &operations;
}
