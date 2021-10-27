#include "ColoredCircle.h"
#include "Circle.h"
#include <stdio.h>

#define Type ColoredCircle
#define Parent Circle

ClassSetup(
    VirtFunCalls(0),
    BindSuperFuns(,
        (Shape, void, draw, (0)),
        (Circle, void, rotate, (0))));

DefaultSetProp(Color, color);
DefaultGetProp(Color, color);

Init
{
    me->d.color = params.color;
    s_params->origin = params.origin;
    s_params->radius = params.radius;
    // Circle_init(Cbject_cast(me, Circle), (CircleParams){params.origin.x, params.origin.y, params.radius});
}

Terminate {}

SuperFun(void, draw, (0))
{
    super_Shape_draw(Cbject_cast(me, Shape));
    super_Circle_draw(Cbject_cast(me, Circle));
    printf("ColoredCircle draw\n");
}

SuperFun(void, rotate, (0))
{
    super_Circle_rotate(Cbject_cast(me, Circle));
    printf("Rotate counter-clockwise\n");
}

#undef Parent
#undef Type
