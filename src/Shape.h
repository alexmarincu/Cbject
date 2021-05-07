#ifndef SHAPE_H
#define SHAPE_H
#include "Cbject/Cbject.h"
#include "Point.h"

#define CbjectType Shape
#define parent Cbject

AbstractClass(
    Params(_, Point origin),
    Props(_, Point origin),
    VirtualFuns(_,
        (float, area, (0)),
        (void, draw, (_, uint8 const a))));

Setters(_, (Point, origin));
Getters(_, (Point, origin));
OverrideFun(void, draw, (_, uint8 const a));

#undef parent
#undef CbjectType
#endif // SHAPE_H
