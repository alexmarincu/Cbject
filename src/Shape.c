#include "Shape.h"
#include <stdio.h>

#define klass Shape
#define superKlass Cbject

AbstractKlassSetup({ BindVirtualFunctions(area, draw); });

Init { me->p.origin = params->origin; }

Terminate {}
DefaultSetter(Point, origin);
DefaultGetter(Point, origin);

VirtualFunction(float, area, (0), (0));
SuperFunction(float, area, (0))
{
    (void) me;
    return 0;
}

VirtualFunction(void, draw, (_, uint8 const a), (_, a));
SuperFunction(void, draw, (_, uint8 const a))
{
    (void) me;
    printf("Shape draw\n");
}

Function(void, dummy, (0)) { printf("Shape dummy\n"); }

#undef superKlass
#undef klass
