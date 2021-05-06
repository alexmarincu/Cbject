#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

#define CbjectType Circle
#define parent Shape

Class(
    Params(_,
        Point origin,
        uint32 radius),
    Props(_, int32 radius),
    VirtualFuns(_, (void, rotate, (0))));

PublicConst(float, pi);
PublicConsts((float, anotherPi));

Set(uint32, radius);
Get(uint32, radius);

OverrideFuns(_,
    (float, area, (0)),
    (void, draw, (_, uint8 const a)));

Funs(_, (void, rotate, (0)));

#undef CbjectType
#undef parent
#endif // CIRCLE_H
