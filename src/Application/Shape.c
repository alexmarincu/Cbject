#include "Shape.h"
#include <stdio.h>

#undef Type
#define Type Shape

AbstractClassSetup(
    NA,
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

SetterImpl(Point, origin);
GetterImpl(Point, origin);

FunOverride(void, draw, NA)
{
    printf("Shape draw\n");
}

#undef Type
