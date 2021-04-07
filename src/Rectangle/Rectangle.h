#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Point.h"

#define class Rectangle
//==>
classParams(
    Point const origin,
    uint32 const width,
    uint32 const height);

settersGetters(
    (uint32, width),
    (uint32, height));

function(uint32, test, (uint32 const a));
//<==
#undef class
#endif // RECTANGLE_H
