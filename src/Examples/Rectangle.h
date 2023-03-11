#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Drawable.h"

typedef struct Rectangle Rectangle;
typedef struct RectangleClass RectangleClass;

/*************************************************************************** @startuml(id=Rectangle)
object Rectangle {
    Drawable drawable;
    uint32_t width;
    uint32_t height;
}
@enduml *******************************************************************************************/
struct Rectangle {
    Drawable drawable;
    uint32_t width;
    uint32_t height;
};

/********************************************************************** @startuml(id=RectangleClass)
object RectangleClass {
    DrawableClass drawableClass;
}
@enduml *******************************************************************************************/
struct RectangleClass {
    DrawableClass drawableClass;
};

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
RectangleClass const * RectangleClass_instance(void);

#endif // RECTANGLE_H
