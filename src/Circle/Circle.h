#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Shape.h"

#define class Circle
//==>
publicConstant(float, pi);
publicConstants((float, anotherPi));

classParams(
    Point const origin,
    uint32 const radius);

    enum{CircleClass_sizes = sizeof(struct{uint8 _[ShapeClass_sizes]; uint32 radius;})};

setterGetter(uint32, radius);
function(void, rotate, ());
//<==
#undef class
#endif // CIRCLE_H
