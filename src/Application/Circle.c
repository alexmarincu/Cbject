#include "Circle.h"
#include <stdio.h>

#define Type Circle
#define Parent Shape

ClassSetup(
    VirtFunCalls(,
        (void, rotate, (0), (0))),
    BindSuperFuns(,
        (Shape, float, area, (0)),
        (Shape, void, draw, (0)),
        (Circle, void, rotate, (0))));

Const(float, pi = 3.14);
static Const(float, privatePi = 3.14);

Init
{
    me->d.radius = params.radius;
    Shape_init((Shape *) (me), (ShapeParams){params.origin.x, params.origin.y});
}

Terminate {}

DefaultSetProp(uint32, radius);
DefaultGetProp(uint32, radius);

SuperFun(void, draw, (0))
{
    super_Shape_draw((Shape *) me);
    printf("Circle draw\n");
}

SuperFun(float, area, (0)) { return me->d.radius * me->d.radius * Circle_pi; }
SuperFun(void, rotate, (0)) { printf("Rotate clockwise\n"); }

#undef Parent
#undef Type
