#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

#define klass Circle
#define superKlass Shape

Klass(
    Params(_,
        Point origin,
        uint32 radius),
    Properties(_, int32 radius),
    VirtualFunctions(_, (void, rotate, (0))));

PublicConstant(float, pi);
PublicConstants((float, anotherPi));

// setterGetter(uint32, radius);
Setter(uint32, radius);
Getter(uint32, radius);

SuperFunctions(_,
    (float, area, (0)),
    (void, draw, (_, uint8 const a)));

Functions(_, (void, rotate, (0)));

#undef klass
#undef superKlass
#endif // CIRCLE_H
