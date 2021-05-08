#include "Shape.h"
#include <stdio.h>

#define Type Shape
#define Parent Cbject

AbstractClassSetup(
    VirtFunCalls(_,
        (float, area, (0), (0)),
        (void, draw, (_, uint8 const a), (_, a))),
    BindFuns(_,
        (void, Shape, draw, (_, uint8 const a))));

Init { me->p.origin = params->origin; }
Terminate {}

DefaultSet(Point, origin);
DefaultGet(Point, origin);

SuperFun(void, draw, (_, uint8 const a))
{
    (void) me;
    printf("Shape draw\n");
}

Fun(void, dummy, (0)) { printf("Shape dummy\n"); }

#undef Parent
#undef Type
