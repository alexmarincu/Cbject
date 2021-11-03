#ifndef SHAPE_H
#define SHAPE_H
#include "../Cbject/Cbject.h"
#include "Point.h"

#define Type Shape
#define Parent Object

AbstractClass(
    Params(
        Point origin),
    Data(
        Point origin),
    VirtFuns(
        (virtualPure, (float, area, ParamsNone)),
        (virtual, (void, draw, ParamsNone))));

SetProp(Point, origin);
GetProp(Point, origin);

#undef Parent
#undef Type
#endif // SHAPE_H
