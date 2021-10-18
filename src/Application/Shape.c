#include "Shape.h"
#include <stdio.h>

#define Type Shape
#define Parent Cbject

AbstractClassSetup(
    VirtFunCalls(,
        (float, area, (0), (0)),
        (void, draw, (0), (0))),
    BindSuperFuns(,
        (Shape, void, draw, (0))));

Init { me->props.origin = params->origin; }

DefaultSetProp(Point, origin);
DefaultGetProp(Point, origin);

SuperFun(void, draw, (0))
{
    (void) me;
    printf("Shape draw\n");
}

Fun(void, dummy, (0)) { printf("Shape dummy\n"); }

#undef Parent
#undef Type
