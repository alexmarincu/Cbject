#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Drawable.h"

typedef struct Rectangle Rectangle;
typedef struct RectangleClass RectangleClass;

/*************************************************************************** @startuml(id=Rectangle)
object Rectangle {
    Drawable super;
    uint32_t width;
    uint32_t height;
}
@enduml *******************************************************************************************/
struct Rectangle {
    Drawable super;
    uint32_t width;
    uint32_t height;
};

/********************************************************************** @startuml(id=RectangleClass)
object RectangleClass {
    DrawableClass super;
}
@enduml *******************************************************************************************/
struct RectangleClass {
    DrawableClass super;
};

Rectangle * Rectangle_init(
    Rectangle * const self,
    Point origin,
    uint32_t width,
    uint32_t height
);
uint32_t Rectangle_getWidth(Rectangle const * const self);
void Rectangle_setWidth(Rectangle * const self, uint32_t const width);
uint32_t Rectangle_getHeight(Rectangle const * const self);
void Rectangle_setHeight(Rectangle * const self, uint32_t const height);
void Rectangle_makeSquare(Rectangle * const self, uint32_t const edgeSize);
RectangleClass * RectangleClass_instance(void);

#endif // RECTANGLE_H
