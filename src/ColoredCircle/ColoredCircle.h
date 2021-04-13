#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Circle/Circle.h"
#include "Color.h"

#define class ColoredCircle
#define superClass Circle



    #define ColoredCircleMembers \
Color color
InitParams(
    Color const color);
DeclareClass(ColoredCircleMembers);



Setters(
    (uint32, radius),
    (Color, color));

Getters(
    (uint32, radius),
    (Color, color));

#undef class
#undef superClass
#endif // COLOREDCIRCLE_H
