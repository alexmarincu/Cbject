#ifndef COLOREDCIRCLESUPER_H
#define COLOREDCIRCLESUPER_H
#include "../Circle/CircleSuper.h"
#include "ColoredCircle.h"

#undef class
#define class ColoredCircle
#undef super_class
#define super_class Circle

class_members(
    mColor color;);

class_virtual_functions();

#endif // COLOREDCIRCLESUPER_H
