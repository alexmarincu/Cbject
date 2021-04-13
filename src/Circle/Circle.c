#include "Circle.h"
#include <stdio.h>

#define class Circle
#define superClass Shape

AbstractClassMembers(CircleMembe);

PoolSize(10);

Constants(
    (float, pi = 3.14),
    (float, anotherPi = 3.14));

PrivateConstants(
    (float, privatePi = 3.14),
    (float, anotherPrivatePi = 3.14));

ClassSetup({
    BindVirtualFunction(rotate);
    BindFunctions(
        (float, Shape, area, ()),
        (void, Shape, draw, (uint8 const a)));
});

Init({ me->radius = params->radius; });
Terminate({});

// defaultSetterGetter(uint32, radius);
DefaultSetter(uint32, radius);
DefaultGetter(uint32, radius);

OverrideFunction(void, Shape, draw, (uint8 const a))
{
    superShape_draw((Shape *) me, a);
    printf("Circle draw\n");
}

OverrideFunction(float, Shape, area, ()) { return me->radius * me->radius * Circle_pi; }
VirtualFunction(void, rotate, (), ()) { printf("Rotate clockwise\n"); }

#undef superClass
#undef class
