#include "Shape.h"
#include <stdio.h>

#define class Shape
#define superClass Cbject

abstractClassMembers(ShapeMembers);
defaultSetterGetter(Point, origin);
abstractClassSetup({ bindVirtualFunctions(area, draw); });
init({ me->origin = params->origin; });
terminate({});

virtualFunction(float, area, (), ())
{
    (void) me;
    return 0;
}

virtualFunction(void, draw, (uint8 const a), (a))
{
    (void) me;
    printf("Shape draw\n");
}

function(void, dummy, ()) { printf("Shape dummy\n"); }

#undef superClass
#undef class
