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
        ((Point, origin), Access_ReadWrite)),
    VirtFuns(
        ((float, area, ()), VirtFunType_Pure),
        ((void, draw, ()), VirtFunType_Implemented)),
    ());

#undef Parent
#undef Type
#endif // SHAPE_H
