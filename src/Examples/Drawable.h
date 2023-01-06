#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "../cbject/cbject.h"
cbject_typedefInterface(Drawable);
/* @startuml(id=DrawableInterface)
object DrawableInterface {
    cbject_TraitInterface s_cbject_TraitInterface;
    void (*draw)(Drawable const * const drawable);
}
@enduml */
struct DrawableInterface {
    cbject_is(cbject_TraitInterface);
    void (*draw)(Drawable const * const drawable);
};
/* @startuml(id=Drawable)
object Drawable {
    cbject_Trait s_cbject_Trait;
}
@enduml */
struct Drawable {
    cbject_is(cbject_Trait);
    uint16_t scale;
};
DrawableInterface const * DrawableInterface_getInstance(void);
void Drawable_init(Drawable * const drawable, uint16_t const scale);
void Drawable_draw(Drawable const * const drawable);
#endif // DRAWABLE_H
