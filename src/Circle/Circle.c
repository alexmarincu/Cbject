#include "Circle.h"
#include <stdio.h>

#define class Circle
#define superClass Shape

abstractClassMembers(CircleMembers);

classPoolSize(10);

constants(
    (float, pi = 3.14),
    (float, anotherPi = 3.14));

privateConstants(
    (float, privatePi = 3.14),
    (float, anotherPrivatePi = 3.14));

classSetup({
    bindVirtualFunction(rotate);
    bindFunctions(
        (float, Shape, area, ()),
        (void, Shape, draw, (uint8 const a)));
});

init({ me->radius = params->radius; });
terminate({});

defaultSetterGetter(uint32, radius);

overrideFunction(void, Shape, draw, (uint8 const a))
{
    superShape_draw((Shape *) me, a);
    printf("Circle draw\n");
}

overrideFunction(float, Shape, area, ()) { return me->radius * me->radius * Circle_pi; }
virtualFunction(void, rotate, (), ()) { printf("Rotate clockwise\n"); }

#undef superClass
#undef class
