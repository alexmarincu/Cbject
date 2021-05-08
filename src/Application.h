#ifndef APPLICATION_H
#define APPLICATION_H
#include "Cbj/Cbj.h"
#include "Circle.h"
#include "ColoredCircle.h"
#include "Rectangle.h"
#include "Shape.h"

#define Cbj_Type Application
#define Cbj_Parent Cbj_Base

Object(
    Props(_,
        Circle * circle,
        Rectangle * rectangle,
        Rectangle * heapRectangle,
        ColoredCircle * coloredCircle));

Fun(void, start, (0));

#undef Cbj_Parent
#undef Cbj_Type
#endif // APPLICATION_H
