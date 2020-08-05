#include "ColoredCircle.h"
#include "../Circle/super_Circle.h"
#include <stdio.h>

#define Class_ ColoredCircle
#define super_Class_ Circle

class_members(
    Color color);

default_set_get(Color, color);

override_functions(
    (Void, Shape, draw, (UInt8 const a)),
    (Void, Circle, rotate, ()));

class_pool_size(10);

class_setup({
    bind_override_functions(
        (Void, Shape, draw, (UInt8 const a)),
        (Void, Circle, rotate, ()));
});

init({
    Circle_init(
        (Circle *) this_,
        &((CircleInitParams){
            .origin.x = 0,
            .origin.y = 0,
            .radius = params->radius}));

    this_->color = params->color;
});

terminate({ Circle_terminate((Circle *) this_); });

override_fun(Void, Shape, draw, (UInt8 const a))
{
    super_Shape_draw((Shape *) this_, 5);
    super_Circle_draw((Circle *) this_, 5);
    printf("ColoredCircle draw\n");
}

override_fun(Void, Circle, rotate, ())
{
    super_Circle_rotate((Circle *) this_);
    printf("Rotate counter-clockwise\n");
}

#undef super_Class_
#undef Class_
