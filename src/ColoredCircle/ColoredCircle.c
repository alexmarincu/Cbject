#include "ColoredCircle.h"
#include "../Circle/Circle.h"
#include <stdio.h>

#define klass ColoredCircle
#define superKlass Circle

PoolSize(10);

OverrideFunctions(
    (void, Shape, draw, (uint8 const a)),
    (void, Circle, rotate, ()));

KlassSetup({
    BindFunctions(
        (void, Shape, draw, (uint8 const a)),
        (void, Circle, rotate, ()));
});

DefaultSetter(Color, color);
DefaultGetter(Color, color);

Init({
    Circle_init(
        (Circle *) me,
        &((CircleInitParams){
            .origin.x = params->origin.x,
            .origin.y = params->origin.y,
            .radius = params->radius}));

    me->m.color = params->color;
});

Terminate({});

OverrideFunctionNew(Shape, (void, draw, (uint8 const a)))
{
    superShape_draw((Shape *) me, 5);
    superCircle_draw((Circle *) me, 5);
    printf("ColoredCircle draw\n");
}

OverrideFunctionNew(Circle, (void, rotate, ()))
{
    superCircle_rotate((Circle *) me);
    printf("Rotate counter-clockwise\n");
}

#undef superKlass
#undef klass
