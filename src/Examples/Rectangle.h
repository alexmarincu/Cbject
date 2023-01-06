#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../cbject/cbject.h"
#include "Drawable.h"
#include "Shape.h"
cbject_typedefClass(Rectangle);
/* @startuml(id=RectangleClass)
object RectangleClass {
    ShapeClass s_ShapeClass;
    DrawableInterface ss_DrawableInterface;
}
@enduml */
struct RectangleClass {
    cbject_is(ShapeClass);
    cbject_has(DrawableInterface);
};
RectangleClass const * RectangleClass_getInstance(void);
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
