#include "Rectangle.h"
#include "../Shape/ShapeSuper.h"

#undef Class
#define Class Rectangle
#undef SuperClass
#define SuperClass Shape

class_members(
    UInt32 width,
    UInt32 height);

override_fun(Float, Shape, area, ());

class_init({
    Shape_init((Shape *) _this, (ShapeInitParams *) params);
    setup_virtual_functions({ bind_override_functions((Float, Shape, area, ())); });
    _this->width = params->width;
    _this->height = params->height;
});

default_setters_getters(
    (UInt32, width),
    (UInt32, height));

fun(UInt32, test, (UInt32 const a)) { return a; }
override_fun(Float, Shape, area, ()) { return _this->width * _this->height; }
