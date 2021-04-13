#include "Rectangle.h"
#include "../Shape/Shape.h"

#define class Rectangle
#define superClass Shape

PoolSize(10);

ClassMembers(RectangleMembers);

DefaultSetters(
    (uint32, width),
    (uint32, height));

DefaultGetters(
    (uint32, width),
    (uint32, height));

OverrideFunction(float, Shape, area, ());
ClassSetup({ BindFunction(float, Shape, area, ()); });

Init({
    me->width = params->width;
    me->height = params->height;
});

Terminate({});
Function(uint32, test, (uint32 const a)) { return a; }
OverrideFunction(float, Shape, area, ()) { return me->width * me->height; }

#undef superClass
#undef class
