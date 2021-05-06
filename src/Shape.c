#include "Shape.h"
#include <stdio.h>

#define CbjectType Shape
#define parent Cbject

AbstractClassSetup(
    VirtualFunCalls(_,
        (float, area, (0), (0)),
        (void, draw, (_, uint8 const a), (_, a))),
    BindFuns(_,
        (void, Shape, draw, (_, uint8 const a))));

Init { me->p.origin = params->origin; }
Terminate {}

DefaultSet(Point, origin);
DefaultGet(Point, origin);

OverrideFun(void, draw, (_, uint8 const a))
{
    (void) me;
    printf("Shape draw\n");
}

Fun(void, dummy, (0)) { printf("Shape dummy\n"); }

#undef parent
#undef CbjectType
