#include "Shape.h"
#include <stdio.h>

#define Type Shape
#define Parent Object

AbstractClassSetup(
    VirtFunCalls(
        (float, area, (), ()),
        (void, draw, (), ())),
    FunOverrides(
        (Shape, (void, draw, ()))));

Init
{
    me->data.origin = params.origin;
}

Terminate {}

SetImpl(Point, origin);
GetImpl(Point, origin);

FunOverride(void, draw, ())
{
    printf("Shape draw\n");
}

Fun(void, dummy, ()) { printf("Shape dummy\n"); }

#undef Parent
#undef Type
