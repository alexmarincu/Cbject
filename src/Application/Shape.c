#include "Shape.h"
#include <stdio.h>

#define Type Shape
#define Parent Cbject

AbstractClassSetup(
    VirtFunCalls(_,
        (float, area, (0), (0)),
        (void, draw, (0), (0))),
    BindSuperFuns(_,
        (Shape, void, draw, (0))));

Init { me->props.origin = params->origin; }
Terminate {}

DefaultSet(Point, origin);
DefaultGet(Point, origin);

SuperFun(void, draw, (0))
{
    (void) me;
    printf("Shape draw\n");
}

Fun(void, dummy, (0)) { printf("Shape dummy\n"); }

#undef Parent
#undef Type
