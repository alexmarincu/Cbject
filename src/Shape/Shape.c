#include "Shape.h"
#include <stdio.h>

#define class Shape
#define superClass Cbject

AbstractClassMembers(ShapeMembers);
// defaultSetterGetter(Point, origin);
DefaultSetter(Point, origin);
DefaultGetter(Point, origin);
AbstractClassSetup({ BindVirtualFunctions(area, draw); });
Init({ me->origin = params->origin; });
Terminate({});

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

Function(void, dummy, ()) { printf("Shape dummy\n"); }

#undef superClass
#undef class
