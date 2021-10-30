#include "ColoredCircle.h"
#include "Circle.h"
#include <stdio.h>

#define Type ColoredCircle
#define Parent Circle

ClassSetup(
    (0),
    BindSuperFuns(
        (Shape, void, draw, (0)),
        (Circle, void, rotate, (0))));

DefaultSetProp(Color, color);
DefaultGetProp(Color, color);

Init
{
    me->d.color = params.color;
    s_params->origin = params.origin;
    s_params->radius = params.radius;
    // Circle_init(Cast(me, Circle), (CircleParams){params.origin.x, params.origin.y, params.radius});
}

Terminate {}

SuperFun(void, draw, (0))
{
    super_Shape_draw(Cast(Shape, me));
    super_Circle_draw(Cast(Circle, me));
    printf("ColoredCircle draw\n");
}

SuperFun(void, rotate, (0))
{
    super_Circle_rotate(Cast(Circle, me));
    printf("Rotate counter-clockwise\n");
}

#undef Parent
#undef Type
