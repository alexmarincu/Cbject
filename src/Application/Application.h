#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Cbject/Cbject.h"
#include "Circle.h"
#include "ColoredCircle.h"
#include "Rectangle.h"
#include "Shape.h"

#define Type Application
#define Parent Object

Singleton(
    Data(
        Circle * circle,
        Rectangle * rectangle,
        Rectangle * heapRectangle,
        ColoredCircle * coloredCircle),
    Funs(
        (Final, (void, start, ()))));

#undef Parent
#undef Type
#endif // APPLICATION_H
