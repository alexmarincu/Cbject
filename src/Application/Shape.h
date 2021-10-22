#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"

#define Type Shape
#define Parent Cbject

AbstractClass(
    Params(, Point origin),
    Props(, Point origin),
    VirtFuns(,
        (float, area, (0)),
        (void, draw, (0))));

SetProps(, (Point, origin));
GetProps(, (Point, origin));
SuperFun(void, draw, (0));

#undef Parent
#undef Type
#endif // SHAPE_H
