#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

#define Type Circle
#define Parent Shape

Class(
    Params(,
        Point origin,
        uint32 radius),
    Props(, int32 radius),
    VirtFuns(, (void, rotate, (0))));

PublicConst(float, pi);
PublicConsts(, (float, anotherPi));

SetProp(uint32, radius);
GetProp(uint32, radius);

SuperFuns(,
    (float, area, (0)),
    (void, draw, (0)),
    (void, rotate, (0)));

#undef Type
#undef Parent
#endif // CIRCLE_H
