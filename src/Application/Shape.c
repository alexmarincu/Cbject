#include "Shape.h"
#include <stdio.h>

#define Type Shape
#define Parent Cbject

AbstractClassSetup(
    VirtFunCalls(
        (float, area, (void), (void)),
        (void, draw, (void), (void))),
    BindFuns(
        (Shape, void, draw, (void))));

Init { me->d.origin = p.origin; }
Terminate {}

DefaultSetProp(Point, origin);
DefaultGetProp(Point, origin);

OverrideFun(void, draw, (void))
{
    (void)me;
    printf("Shape draw\n");
}

Fun(void, dummy, (void)) { printf("Shape dummy\n"); }

#undef Parent
#undef Type
