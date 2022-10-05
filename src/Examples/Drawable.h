#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "../Cbject/Cbject.h"
typedefInterface_(Drawable);
/* @startuml(id=DrawableInterface)
object DrawableInterface {
    TraitInterface super;
    void (*draw)(Drawable const * const drawable);
}
@enduml */
struct DrawableInterface {
    extends_(TraitInterface);
    void (*draw)(Drawable const * const drawable);
};
/* @startuml(id=Drawable)
object Drawable {
    Trait super;
}
@enduml */
struct Drawable {
    extends_(Trait);
    uint16_t scale;
};
DrawableInterface const * DrawableInterface_instance(void);
void DrawableInterface_init(void);
void Drawable_init(Drawable * const drawable, uint16_t const scale);
void Drawable_draw(Drawable const * const drawable);
#endif // DRAWABLE_H
