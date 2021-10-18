#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Cbj/Cbj.h"
#include "Circle.h"
#include "ColoredCircle.h"
#include "Rectangle.h"
#include "Shape.h"

#define Type Application
#define Parent Cbject

Object(
    Props(,
        Circle * circle,
        Rectangle * rectangle,
        Rectangle * heapRectangle,
        ColoredCircle * coloredCircle));

Fun(void, start, (0));

#undef Parent
#undef Type
#endif // APPLICATION_H
