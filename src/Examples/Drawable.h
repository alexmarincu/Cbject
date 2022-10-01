#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "../Cbject/Cbject.h"
typedef struct Drawable_Interface Drawable_Interface;
typedef struct Drawable Drawable;
/* @startuml(id=Drawable_Interface)
object Drawable_Interface {
    Trait_Interface super;
    void (*draw)(Drawable const * const drawable);
}
@enduml */
struct Drawable_Interface {
    extends_(Trait_Interface);
    void (*draw)(Drawable const * const drawable);
};
/* @startuml(id=Drawable)
object Drawable {
    Trait super;
}
@enduml */
struct Drawable {
    extends_(Trait);
};
Drawable_Interface const * Drawable_Interface_(void);
Drawable * Drawable_init(Drawable * const drawable);
void Drawable_draw(Drawable const * const drawable);
#endif // DRAWABLE_H
