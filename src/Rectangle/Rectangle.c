#include "Rectangle.h"
#include "../Shape/ShapeSuper.h"

#undef class
#define class Rectangle
#undef super_class
#define super_class Shape

class_members(
    UInt32 width,
    UInt32 height);

override_fun(Float, Shape, area, ());

class_init({
    Shape_init((Shape *) me, (ShapeInitParams *) params);
    setup_virtual_functions({ bind_override_functions((Float, Shape, area, ())); });
    me->width = params->width;
    me->height = params->height;
});

default_setters_getters(
    (UInt32, width),
    (UInt32, height));

fun(UInt32, test, (UInt32 const a)) { return a; }
override_fun(Float, Shape, area, ()) { return me->width * me->height; }
