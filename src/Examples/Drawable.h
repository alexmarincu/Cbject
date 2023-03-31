#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Shape.h"

typedef struct Drawable Drawable;
typedef struct Drawable_Class Drawable_Class;

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

/*********************************************************************** @startuml(id=Drawable_Class)
object Drawable_Class {
    Shape_Class super;
    void (*draw)(Drawable const * const self);
}
@enduml *******************************************************************************************/
struct Drawable_Class {
    Shape_Class super;
    void (*draw)(Drawable const * const self);
};

void Drawable_init(
    Drawable * const self,
    Point origin,
    uint16_t const scale
);
void Drawable_draw(Drawable const * const self);
Drawable_Class * Drawable_Class_instance(void);

#endif // DRAWABLE_H
