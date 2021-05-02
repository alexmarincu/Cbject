#include "ColoredCircle.h"
#include "Circle.h"
#include <stdio.h>

#define klass ColoredCircle
#define superKlass Circle

PoolSize(10);

SuperFunctions(_,
    (void, draw, (_, uint8 const a)),
    (void, rotate, (0)));

KlassSetup({
    BindFunctions(
        (void, Shape, draw, (uint8 const a)),
        (void, Circle, rotate, ()));
});

DefaultSetter(Color, color);
DefaultGetter(Color, color);

Init({
    superParams =
        (CircleParams){
            .origin.x = params->origin.x,
            .origin.y = params->origin.y,
            .radius = params->radius};

    me->p.color = params->color;
});

Terminate({});

SuperFunction(void, draw, (_, uint8 const a))
{
    sShape_draw((Shape *) me, 5);
    sCircle_draw((Circle *) me, 5);
    printf("ColoredCircle draw\n");
}

SuperFunction(void, rotate, (0))
{
    sCircle_rotate((Circle *) me);
    printf("Rotate counter-clockwise\n");
}

#undef superKlass
#undef klass
