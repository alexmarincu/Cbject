#include "Circle.h"
#include <stdio.h>

#define klass Circle
#define superKlass Shape

PoolSize(10);

Constants(
    (float, pi = 3.14),
    (float, anotherPi = 3.14));

PrivateConstants(
    (float, privatePi = 3.14),
    (float, anotherPrivatePi = 3.14));

KlassSetup({
    BindVirtualFunction(rotate);
    BindFunctions(
        (float, Shape, area, ()),
        (void, Shape, draw, (uint8 const a)));
});

Init({
    superInitParams =
        (ShapeInitParams){
            .origin.x = params->origin.x,
            .origin.y = params->origin.y};

    me->m.radius = params->radius;
});

Terminate({});

DefaultSetter(uint32, radius);
DefaultGetter(uint32, radius);

SuperFunction(void, draw, (_, uint8 const a))
{
    superShape_draw((Shape *) me, a);
    printf("Circle draw\n");
}

SuperFunction(float, area, (0)) { return me->m.radius * me->m.radius * Circle_pi; }
VirtualFunction(void, rotate, (0), (0)) { printf("Rotate clockwise\n"); }

#undef superKlass
#undef klass
