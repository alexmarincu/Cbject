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
        (void, draw, (0))));

SetProps(_, (Point, origin));
GetProps(_, (Point, origin));
SuperFun(void, draw, (0));

#undef Parent
#undef Type
#endif // SHAPE_H
