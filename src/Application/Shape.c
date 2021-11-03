#include "Shape.h"
#include <stdio.h>

#define Type Shape
#define Parent Object

AbstractClassSetup(
    VirtFunCalls(
        (float, area, ParamsNone, ParamsNone),
        (void, draw, ParamsNone, ParamsNone)),
    BindFuns(
        (Shape, (void, draw, ParamsNone))));

Init { me->d.origin = p.origin; }
Terminate {}

DefaultSetProp(Point, origin);
DefaultGetProp(Point, origin);

OverrideFun(void, draw, ParamsNone)
{
    printf("Shape draw\n");
}

Fun(void, dummy, ParamsNone) { printf("Shape dummy\n"); }

#undef Parent
#undef Type
