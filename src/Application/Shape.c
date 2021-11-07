#include "Shape.h"
#include <stdio.h>

#define Type Shape
#define Parent Object

AbstractClassSetup(
    VirtFunSetup(
        ((float, area, NA), NA),
        ((void, draw, NA), NA)),
    FunOverrideSetup(
        ((void, draw, NA), Shape)));

Init
{
    me->data.origin = params.origin;
}

Terminate {}

SetImpl(Point, origin);
GetImpl(Point, origin);

FunOverride(void, draw, NA)
{
    printf("Shape draw\n");
}

Fun(void, dummy, NA) { printf("Shape dummy\n"); }

#undef Parent
#undef Type
