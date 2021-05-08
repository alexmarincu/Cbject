#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbj/Cbj.h"
#include "Point.h"

#define Type Shape
#define Parent Cbject

AbstractClass(
    Params(_, Point origin),
    Props(_, Point origin),
    VirtFuns(_,
        (float, area, (0)),
        (void, draw, (_, uint8 const a))));

Setters(_, (Point, origin));
Getters(_, (Point, origin));
SuperFun(void, draw, (_, uint8 const a));

#undef Parent
#undef Type
#endif // SHAPE_H
