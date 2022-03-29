#include "Shape.h"

/**
 * @brief
 *
 * @param this_
 * @return float
 */
float Shape_area(Shape const * const this_) {
    return interfaceOperationCall_(Shape, area, this_);
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
    static bool isInitialized = false;

    if (!isInitialized) {
        operations.area = area;
        isInitialized = true;
    }

    return &operations;
}
