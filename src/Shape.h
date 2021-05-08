#ifndef SHAPE_H
#define SHAPE_H
#include "Cbj/Cbj.h"
#include "Point.h"

#define Cbj_Type Shape
#define Cbj_Parent Cbj_Base

AbstractClass(
    Params(_, Point origin),
    Props(_, Point origin),
    VirtFuns(_,
        (float, area, (0)),
        (void, draw, (_, uint8 const a))));

Setters(_, (Point, origin));
Getters(_, (Point, origin));
OverrideFun(void, draw, (_, uint8 const a));

#undef Cbj_Parent
#undef Cbj_Type
#endif // SHAPE_H
