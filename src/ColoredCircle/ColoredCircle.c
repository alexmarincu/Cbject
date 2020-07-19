#include "ColoredCircle.h"
#include "../Circle/super_Circle.h"
#include <stdio.h>

#undef Class_
#define Class_ ColoredCircle
#undef super_Class_
#define super_Class_ Circle

class_members(
    Color color);

default_set_get(Color, color);
override_fun(Void, Shape, draw, (UInt8 const a));

class_pool_size(10);
class_setup({ bind_override_fun(Void, Shape, draw, (UInt8 const a)); });

init({
    Circle_init(
        (Circle *) this_,
        &((CircleInitParams){
            .origin.x = 0,
            .origin.y = 0,
            .radius = params->radius}));

    this_->color = params->color;
});

override_fun(Void, Shape, draw, (UInt8 const a))
{
    printf("ColoredCircle draw\n");
}
