#include "ColoredCircle.h"
#include "Circle.h"
#include <stdio.h>

#define Type ColoredCircle
#define Parent Circle

ClassSetup(
    (),
    BindFuns(
        (Shape, (void, draw, ())),
        (Circle, (void, rotate, ()))));

Setter(Color, color);
Getter(Color, color);

Init
{
    me->data.color = params.color;
    superParams->origin = params.origin;
    superParams->radius = params.radius;
}

Terminate {}

OverrideFun(void, draw, ())
{
    super_Shape_draw(Cast(Shape, me));
    super_Circle_draw(Cast(Circle, me));
    printf("ColoredCircle draw\n");
}

OverrideFun(void, rotate, ())
{
    super_Circle_rotate(Cast(Circle, me));
    printf("Rotate counter-clockwise\n");
}

#undef Parent
#undef Type
