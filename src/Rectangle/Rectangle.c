#include "Rectangle.h"
#include "../Shape/Shape.h"

#define class Rectangle
#define superClass Shape

PoolSize(10);

ClassMembers();

DefaultSetters(
    (uint32, width),
    (uint32, height));

DefaultGetters(
    (uint32, width),
    (uint32, height));

OverrideFunction(float, Shape, area, ());
ClassSetup({ BindFunction(float, Shape, area, ()); });

Init({
    me->m.width = params->width;
    me->m.height = params->height;
});

Terminate({});
Function(uint32, test, (uint32 const a)) { return a; }
OverrideFunction(float, Shape, area, ()) { return me->m.width * me->m.height; }

#undef superClass
#undef class
