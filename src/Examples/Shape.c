#include "Shape.h"

/**
 * @brief Calculates area of a shape
 *
 * @param me The shape's interface
 * @return float The area of the shape
 */
float Shape_area(Shape const * const me) {
    return interfaceCall_(Shape, area, me);
}
static float area(Shape const * const me) {
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
