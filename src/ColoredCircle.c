#include "ColoredCircle.h"
#include "Circle.h"
#include <stdio.h>

#define Cbj_Type ColoredCircle
#define Cbj_Parent Circle

PoolSize(10);

ClassSetup(
    VirtFunCalls(0),
    BindFuns(_,
        (void, Shape, draw, (_, uint8 const a)),
        (void, Circle, rotate, (0))));

DefaultSet(Color, color);
DefaultGet(Color, color);

Init
{
    *s_params = (CircleParams){
        .origin.x = params->origin.x,
        .origin.y = params->origin.y,
        .radius = params->radius};

    me->p.color = params->color;
}

Terminate {}

OverrideFun(void, draw, (_, uint8 const a))
{
    s_Shape_draw((Shape *) me, 5);
    s_Circle_draw((Circle *) me, 5);
    printf("ColoredCircle draw\n");
}

OverrideFun(void, rotate, (0))
{
    s_Circle_rotate((Circle *) me);
    printf("Rotate counter-clockwise\n");
}

#undef Cbj_Parent
#undef Cbj_Type
