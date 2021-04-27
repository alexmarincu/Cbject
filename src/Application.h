#ifndef APPLICATION_H
#define APPLICATION_H
#include "Cbject/Cbject.h"
#include "Circle.h"
#include "ColoredCircle.h"
#include "Rectangle.h"
#include "Shape.h"

#define klass Application
#define superKlass Cbject

Singleton(
    Params(0),
    Properties(_,
        Circle * circle,
        Rectangle * rectangle,
        Rectangle * heapRectangle,
        ColoredCircle * coloredCircle));

Function(void, start, (0));

#undef superKlass
#undef klass
#endif // APPLICATION_H
