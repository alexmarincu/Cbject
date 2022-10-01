#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Cbject/Cbject.h"
#include "Drawable.h"
#include "Shape.h"
typedef struct Rectangle_Class Rectangle_Class;
typedef struct Rectangle Rectangle;
struct Rectangle_Class {
    extends_(Shape_Class);
    implements_(Drawable_Interface);
};
Rectangle_Class const * Rectangle_Class_(void);
Rectangle * Rectangle_init(
    Rectangle * rectangle,
    Point origin,
    uint32_t width,
    uint32_t height
);
uint32_t Rectangle_getWidth(Rectangle const * const rectangle);
void Rectangle_setWidth(Rectangle * const rectangle, uint32_t const width);
uint32_t Rectangle_getHeight(Rectangle const * const rectangle);
void Rectangle_setHeight(Rectangle * const rectangle, uint32_t const height);
void Rectangle_makeSquare(Rectangle * const rectangle, uint32_t const edgeSize);
#endif // RECTANGLE_H
