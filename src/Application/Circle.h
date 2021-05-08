#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

#define Type Circle
#define Parent Shape

Class(
    Params(_,
        Point origin,
        uint32 radius),
    Props(_, int32 radius),
    VirtFuns(_, (void, rotate, (0))));

PublicConst(float, pi);
PublicConsts(_, (float, anotherPi));

Set(uint32, radius);
Get(uint32, radius);

SuperFuns(_,
    (float, area, (0)),
    (void, draw, (_, uint8 const a)),
    (void, rotate, (0)));

#undef Type
#undef Parent
#endif // CIRCLE_H
