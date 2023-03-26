#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Shape.h"

typedef struct Drawable Drawable;
typedef struct DrawableClass DrawableClass;

/**************************************************************************** @startuml(id=Drawable)
object Drawable {
    Shape super;
    uint16_t scale;
}
@enduml *******************************************************************************************/
struct Drawable {
    Shape super;
    uint16_t scale;
};

/*********************************************************************** @startuml(id=DrawableClass)
object DrawableClass {
    ShapeClass super;
    void (*draw)(Drawable const * const self);
}
@enduml *******************************************************************************************/
struct DrawableClass {
    ShapeClass super;
    void (*draw)(Drawable const * const self);
};

void Drawable_init(
    Drawable * const self,
    Point origin,
    uint16_t const scale
);
void Drawable_draw(Drawable const * const self);
DrawableClass * DrawableClass_instance(void);

#endif // DRAWABLE_H
