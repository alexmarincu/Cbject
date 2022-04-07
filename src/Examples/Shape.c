#include "Shape.h"

/**
 * @brief Calculates area of a shape
 *
 * @param this_ The shape's interface
 * @return float The area of the shape
 */
float Shape_area(Shape const * const this_) {
    return interfaceCall_(Shape, area, this_);
}
static float area(Shape const * const this_) {
    assert_(false && "function not overriden");
    return 1;
}

/**
 * @brief Gets reference to ShapeOperations
 * @remark At first call the initialization is done
 *
 * @return ShapeOperations const* The reference to ShapeOperations
 */
ShapeOperations const * ShapeOperations_(void) {
    static ShapeOperations operations;

    doOnce_({
        operations.area = area;
    });

    return &operations;
}
