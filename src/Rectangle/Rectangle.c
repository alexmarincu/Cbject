#include "Rectangle.h"
#include "../Shape/Shape.h"

#define class Rectangle
#define superClass Shape

PoolSize(10);

OverrideFunctionNew(Shape, (float, area, ()));
ClassSetup({ BindFunction(float, Shape, area, ()); });
DefaultSetters(
    (uint32, width),
    (uint32, height));

DefaultGetters(
    (uint32, width),
    (uint32, height));

Init({
    me->m.width = params->width;
    me->m.height = params->height;
});

Terminate({});
Function(uint32, test, (uint32 const a)) { return a; }
OverrideFunctionNew(Shape, (float, area, ())) { return me->m.width * me->m.height; }

#undef superClass
#undef class
