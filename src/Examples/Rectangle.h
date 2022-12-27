#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Cbject/Cbject.h"
#include "Drawable.h"
#include "Shape.h"
x_typedefClass(Rectangle);
/* @startuml(id=RectangleClass)
object RectangleClass {
    ShapeClass eShapeClass;
    DrawableInterface iDrawableInterface;
}
@enduml */
struct RectangleClass {
    x_extends(ShapeClass);
    x_implements(DrawableInterface);
};
RectangleClass const * RectangleClass_instance(void);
Rectangle * Rectangle_init(
    Rectangle * const rectangle,
    Point origin,
    uint32_t width,
    uint32_t height
);
uint32_t Rectangle_getWidth(Rectangle const * const rectangle);
void Rectangle_setWidth(Rectangle * const rectangle, uint32_t const width);
uint32_t Rectangle_getHeight(Rectangle const * const rectangle);
void Rectangle_setHeight(Rectangle * const rectangle, uint32_t const height);
void Rectangle_makeSquare(Rectangle * const rectangle, uint32_t const edgeSize);
#endif // RECTANGLE_H
