#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Shape.h"

typedef struct Drawable Drawable;
typedef struct DrawableClass DrawableClass;

/**************************************************************************** @startuml(id=Drawable)
object Drawable {
    Shape shape;
    uint16_t scale;
}
@enduml *******************************************************************************************/
struct Drawable {
    Shape shape;
    uint16_t scale;
};

/*********************************************************************** @startuml(id=DrawableClass)
object DrawableClass {
    ShapeClass shapeClass;
    void (*draw)(Drawable const * const drawable);
}
@enduml *******************************************************************************************/
struct DrawableClass {
    ShapeClass shapeClass;
    void (*draw)(Drawable const * const drawable);
};

void Drawable_init(
    Drawable * const drawable,
    Point origin,
    uint16_t const scale
);
void Drawable_draw(Drawable const * const drawable);
DrawableClass const * DrawableClass_instance(void);

#endif // DRAWABLE_H
