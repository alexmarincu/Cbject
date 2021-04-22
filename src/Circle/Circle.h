#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Shape.h"

#define klass Circle
#define superKlass Shape

Klass(
    InitParams(_,
               Point origin,
               uint32 radius),
    Members(_,
            int32 radius),
    VirtualFunctions(_,
                     (void, rotate, ())));

PublicConstant(float, pi);
PublicConstants((float, anotherPi));

// setterGetter(uint32, radius);
Setter(uint32, radius);
Getter(uint32, radius);

OverrideFunctions(
    (float, Shape, area, ()),
    (void, Shape, draw, (uint8 const a)));

Functions(_,
          (void, rotate, ()));

#undef klass
#undef superKlass
#endif // CIRCLE_H
