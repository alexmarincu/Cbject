#ifndef APPLICATION_H
#define APPLICATION_H
#include "Cbject/Cbject.h"
#include "Circle.h"
#include "ColoredCircle.h"
#include "Rectangle.h"
#include "Shape.h"

#define CbjectType Application
#define parent Cbject

Object(
    Props(_,
        Circle * circle,
        Rectangle * rectangle,
        Rectangle * heapRectangle,
        ColoredCircle * coloredCircle));

Fun(void, start, (0));

#undef parent
#undef CbjectType
#endif // APPLICATION_H
