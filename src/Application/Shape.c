#include "Shape.h"
#include <stdio.h>

#define Type Shape
#define Parent Object

AbstractClassSetup(
    VirtFunCalls(
        (float, area, (), ()),
        (void, draw, (), ())),
    BindFuns(
        (Shape, (void, draw, ()))));

Init { me->d.origin = p.origin; }
Terminate {}

DefaultSetProp(Point, origin);
DefaultGetProp(Point, origin);

OverrideFun(void, draw, ())
{
    printf("Shape draw\n");
}

Fun(void, dummy, ()) { printf("Shape dummy\n"); }

#undef Parent
#undef Type
