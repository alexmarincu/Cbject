#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "../Cbject/Cbject.h"
typedef struct Drawable_Interface Drawable_Interface;
typedef struct Drawable Drawable;
struct Drawable_Interface {
    extends_(Trait_Interface);
    void (*draw)(Drawable const * const me);
};
struct Drawable {
    extends_(Trait);
};
Drawable_Interface const * Drawable_Interface_(void);
Drawable * Drawable_init(Drawable * me);
void Drawable_draw(Drawable const * const me);
#endif // DRAWABLE_H
