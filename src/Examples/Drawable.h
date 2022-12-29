#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "../Cbject/Cbject.h"
x_typedefInterface(Drawable);
/* @startuml(id=DrawableInterface)
object DrawableInterface {
    Cbject_TraitInterface s_Cbject_TraitInterface;
    void (*draw)(Drawable const * const drawable);
}
@enduml */
struct DrawableInterface {
    x_is(x_TraitInterface);
    void (*draw)(Drawable const * const drawable);
};
/* @startuml(id=Drawable)
object Drawable {
    Cbject_Trait s_Cbject_Trait;
}
@enduml */
struct Drawable {
    x_is(x_Trait);
    uint16_t scale;
};
DrawableInterface const * DrawableInterface_instance(void);
void Drawable_init(Drawable * const drawable, uint16_t const scale);
void Drawable_draw(Drawable const * const drawable);
#endif // DRAWABLE_H
