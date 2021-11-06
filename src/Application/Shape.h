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
        ((Point, origin), Public)),
    VirtFuns(
        ((float, area, ()), Pure),
        ((void, draw, ()), Implemented)),
    ());

#undef Parent
#undef Type
#endif // SHAPE_H
