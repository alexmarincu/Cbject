#include "ColoredCircle.h"
#include "../Circle/Circle.h"
#include <stdio.h>

#define class ColoredCircle
#define superClass Circle

PoolSize(10);

ClassMembers();

// defaultSetterGetter(Color, color);
DefaultSetter(Color, color);
DefaultGetter(Color, color);

OverrideFunctions(
    (void, Shape, draw, (uint8 const a)),
    (void, Circle, rotate, ()));

ClassSetup({
    BindFunctions(
        (void, Shape, draw, (uint8 const a)),
        (void, Circle, rotate, ()));
});

Init({ me->m.color = params->color; });
Terminate({});

OverrideFunction(void, Shape, draw, (uint8 const a))
{
    superShape_draw((Shape *) me, 5);
    superCircle_draw((Circle *) me, 5);
    printf("ColoredCircle draw\n");
}

OverrideFunction(void, Circle, rotate, ())
{
    superCircle_rotate((Circle *) me);
    printf("Rotate counter-clockwise\n");
}

#undef superClass
#undef class
