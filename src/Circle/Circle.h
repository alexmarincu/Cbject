#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Point.h"

#define class Circle
//==>
publicConstant(float, pi);
publicConstants((float, anotherPi));

classParams(
    Point const origin,
    uint32 const radius);

setterGetter(uint32, radius);
function(void, rotate, ());
//<==
#undef class
#endif // CIRCLE_H
