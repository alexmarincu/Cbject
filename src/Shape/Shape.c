#include "Shape.h"
#include <stdio.h>

#define class Shape
#define superClass Cbject

AbstractClassSetup({ BindVirtualFunctions(area, draw); });
Init({ me->m.origin = params->origin; });
Terminate({});
DefaultSetter(Point, origin);
DefaultGetter(Point, origin);

VirtualFunction(float, area, (), ())
{
    (void) me;
    return 0;
}

VirtualFunction(void, draw, (uint8 const a), (a))
{
    (void) me;
    printf("Shape draw\n");
}

Function(void, CbjectUtilities_feN, ()) { printf("Shape CbjectUtilities_feN\n"); }

#undef superClass
#undef class
