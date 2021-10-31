#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"

#define Type Shape
#define Parent Cbject

AbstractClass(
    Params(
        Point origin),
    Data(
        Point origin),
    VirtFuns(
        (float, area, (void)),
        (void, draw, (void))));

SetProp(Point, origin);
GetProp(Point, origin);
OverrideFun(void, draw, (void));

#undef Parent
#undef Type
#endif // SHAPE_H
