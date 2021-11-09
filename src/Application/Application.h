#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Cbject/Cbject.h"
#include "Circle.h"
#include "ColoredCircle.h"
#include "Rectangle.h"
#include "Shape.h"

#undef Type
#define Type Application

Singleton(
    Object,
    Data(
        ((Circle *, circle), Private),
        ((Rectangle *, rectangle), Private),
        ((Rectangle *, heapRectangle), Private),
        ((ColoredCircle *, coloredCircle), Private)),
    Funs(
        ((void, start, NA), Final)));

#endif // APPLICATION_H
