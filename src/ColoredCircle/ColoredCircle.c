#include "ColoredCircle.h"
#include "../Circle/CircleSuper.h"
#include <stdio.h>

#undef class
#define class ColoredCircle
#undef super_class
#define super_class Circle

class_members(
    mColor color);

default_set_get(Color, color);
override_fun(Void, Shape, draw, (UInt8 a));

class_init({
    Circle_init(
        (mCircle pt) me,
        &((CircleInitParams){
            .origin.x = 0,
            .origin.y = 0,
            .radius = params->radius}));

    setup_virtual_functions({ bind_override_functions((Void, Shape, draw, (UInt8 a))); });
    me->color = params->color;
});

override_fun(Void, Shape, draw, (UInt8 a))
{
    printf("ColoredCircle draw\n");
}
