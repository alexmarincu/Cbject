#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

#define Type Circle
#define Parent Shape

Class(
    Params(
        Point origin,
        uint32 radius),
    Data(
        ((uint32, radius), Access_ReadWrite)),
    VirtFuns(
        ((void, rotate, ()), VirtFunType_Implemented)),
    Funs(
        ((float, area, ()), FunType_Override),
        ((void, draw, ()), FunType_Override)));

PoolSize(10);

extern Const(float, pi);

#undef Type
#undef Parent
#endif // CIRCLE_H
