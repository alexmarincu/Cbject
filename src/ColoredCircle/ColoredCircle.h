#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Circle/Circle.h"
#include "Color.h"

#define class ColoredCircle
#define superClass Circle
//==>
classParams(
    uint32 const radius,
    Color const color);

    #define ColoredCircleMembers \
Color color

classDeclaration(ColoredCircleMembers);

settersGetters(
    (uint32, radius),
    (Color, color));
//<==
#undef class
#undef superClass
#endif // COLOREDCIRCLE_H
