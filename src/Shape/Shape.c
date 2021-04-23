#include "Shape.h"
#include <stdio.h>

#define klass Shape
#define superKlass Cbject

AbstractKlassSetup({ BindVirtualFunctions(area, draw); });

Init({ me->m.origin = params->origin; });

Terminate({});
DefaultSetter(Point, origin);
DefaultGetter(Point, origin);

VirtualFunction(float, area, (0), (0))
{
    (void) me;
    return 0;
}

VirtualFunction(void, draw, (_, uint8 const a), (_, a))
{
    (void) me;
    printf("Shape draw\n");
}

Function(void, dummy, (0)) { printf("Shape dummy\n"); }

#undef superKlass
#undef klass
