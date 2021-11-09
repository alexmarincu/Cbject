#include "Shape.h"
#include <stdio.h>

#undef Type
#define Type Shape

AbstractClassSetup(
    Object,
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

#undef Type
