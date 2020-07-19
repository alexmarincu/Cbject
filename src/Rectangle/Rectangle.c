#include "Rectangle.h"
#include "../Shape/super_Shape.h"

#undef Class_
#define Class_ Rectangle
#undef super_Class_
#define super_Class_ Shape

class_members(
    UInt32 width,
    UInt32 height);

override_fun(Float, Shape, area, ());

class_pool_size(10);
class_setup({ bind_override_fun(Float, Shape, area, ()); });

init({
    Shape_init((Shape *) this_, (ShapeInitParams *) params);
    this_->width = params->width;
    this_->height = params->height;
});

clear({ Shape_clear((Shape *) this_); });

default_setters_getters(
    (UInt32, width),
    (UInt32, height));

fun(UInt32, test, (UInt32 const a)) { return a; }
override_fun(Float, Shape, area, ()) { return this_->width * this_->height; }
