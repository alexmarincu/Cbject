#include "ColoredCircleSuper.h"
#include <stdio.h>

#undef class
#define class ColoredCircle
#undef super_class
#define super_class Circle

default_set_get(Color, color);
override_fun(Void, Shape, draw, (UInt8 a));

class_init(
    Circle_init(
        (mCircle) me,
        &((CircleInitParams){
            .origin.x = 0,
            .origin.y = 0,
            .radius = params->radius}));
    bind_virtual_functions(
        bind_override_fun(Void, Shape, draw, UInt8 a););
    me->color = params->color;);

override_fun(Void, Shape, draw, (UInt8 a))
{
    printf("ColoredCircle draw\n");
}
