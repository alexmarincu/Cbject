#include "ColoredCircle.h"
#include "../Circle/CircleSuper.h"
#include <stdio.h>

#undef Class
#define Class ColoredCircle
#undef SuperClass
#define SuperClass Circle

class_members(
    Color color);

default_set_get(Color, color);
override_fun(Void, Shape, draw, (UInt8 const a));

class_init({
    Circle_init(
        (Circle *) _this,
        &((CircleInitParams){
            .origin.x = 0,
            .origin.y = 0,
            .radius = params->radius}));

    setup_virtual_functions({ bind_override_functions((Void, Shape, draw, (UInt8 const a))); });
    _this->color = params->color;
});

override_fun(Void, Shape, draw, (UInt8 const a))
{
    printf("ColoredCircle draw\n");
}
