#ifndef COLOREDCIRCLE_H
#define COLOREDCIRCLE_H
#include "../Circle/Circle.h"
#include "Color.h"

#define class ColoredCircle
#define superClass Circle

ClassInitParams(
    Color const color);

    #define ColoredCircleMembers \
Color color

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
