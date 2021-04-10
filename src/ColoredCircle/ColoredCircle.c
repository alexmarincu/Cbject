#include "ColoredCircle.h"
#include "../Circle/superCircle.h"
#include <stdio.h>

#define class ColoredCircle
#define superClass Circle

classPoolSize(10);

classMembers(ColoredCircleMembers);

defaultSetterGetter(Color, color);

overrideFunctions(
    (void, Shape, draw, (uint8 const a)),
    (void, Circle, rotate, ()));

classSetup({
    bindFunctions(
        (void, Shape, draw, (uint8 const a)),
        (void, Circle, rotate, ()));
});

init({ me->color = params->color; });
terminate({});

overrideFunction(void, Shape, draw, (uint8 const a))
{
    superShape_draw((Shape *) me, 5);
    superCircle_draw((Circle *) me, 5);
    printf("ColoredCircle draw\n");
}

overrideFunction(void, Circle, rotate, ())
{
    superCircle_rotate((Circle *) me);
    printf("Rotate counter-clockwise\n");
}

#undef superClass
#undef class
