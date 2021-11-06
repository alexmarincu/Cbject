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
        ((Circle *, circle), Private),
        ((Rectangle *, rectangle), Private),
        ((Rectangle *, heapRectangle), Private),
        ((ColoredCircle *, coloredCircle), Private)),
    Funs(
        ((void, start, ()), Final)));

#undef Parent
#undef Type
#endif // APPLICATION_H
