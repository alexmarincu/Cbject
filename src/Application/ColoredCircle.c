#include "ColoredCircle.h"
#include "Circle.h"
#include <stdio.h>

#define Type ColoredCircle
#define Parent Circle

ClassSetup(
    (void),
    BindFuns(
        (Shape, void, draw, (void)),
        (Circle, void, rotate, (void))));

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

OverrideFun(void, draw, (void))
{
    Shape_s_draw(Cast(Shape, me));
    Circle_s_draw(Cast(Circle, me));
    printf("ColoredCircle draw\n");
}

OverrideFun(void, rotate, (void))
{
    Circle_s_rotate(Cast(Circle, me));
    printf("Rotate counter-clockwise\n");
}

#undef Parent
#undef Type
