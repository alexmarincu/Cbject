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
    Circle_init((Circle *) me, (CircleParams){params.origin.x, params.origin.y, params.radius});
}

Terminate {}

SuperFun(void, draw, (0))
{
    super_Shape_draw((Shape *) me);
    super_Circle_draw((Circle *) me);
    printf("ColoredCircle draw\n");
}

SuperFun(void, rotate, (0))
{
    super_Circle_rotate((Circle *) me);
    printf("Rotate counter-clockwise\n");
}

#undef Parent
#undef Type
