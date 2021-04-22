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
    Shape_init(
        (Shape *) me,
        &((ShapeInitParams){
            .origin.x = params->origin.x,
            .origin.y = params->origin.y}));

    me->m.radius = params->radius;
});

Terminate({});

// defaultSetterGetter(uint32, radius);
DefaultSetter(uint32, radius);
DefaultGetter(uint32, radius);

OverrideFunctionNew(Shape, (void, draw, (uint8 const a)))
{
    superShape_draw((Shape *) me, a);
    printf("Circle draw\n");
}

OverrideFunctionNew(Shape, (float, area, ())) { return me->m.radius * me->m.radius * Circle_pi; }
VirtualFunction(void, rotate, (), ()) { printf("Rotate clockwise\n"); }

#undef superKlass
#undef klass
