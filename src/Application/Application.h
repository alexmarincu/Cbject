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
        ((Circle *, circle), Access_None),
        ((Rectangle *, rectangle), Access_None),
        ((Rectangle *, heapRectangle), Access_None),
        ((ColoredCircle *, coloredCircle), Access_None)),
    Funs(
        ((void, start, ()), FunType_Final)));

#undef Parent
#undef Type
#endif // APPLICATION_H
