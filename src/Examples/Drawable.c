#include "Drawable.h"
#include <stdio.h>

void Drawable_draw(Drawable const * const me) {
    return call_(Drawable, draw, me);
}
