#include "Rectangle.h"
#include "../Shape/superShape.h"

#define class Rectangle
#define superClass Shape

classPoolSize(10);

classMembers(RectangleMembers);

defaultSettersGetters(
    (uint32, width),
    (uint32, height));

overrideFunction(float, Shape, area, ());
classSetup({ bindFunction(float, Shape, area, ()); });

init({
    me->width = params->width;
    me->height = params->height;
});

terminate({});
function(uint32, test, (uint32 const a)) { return a; }
overrideFunction(float, Shape, area, ()) { return me->width * me->height; }

#undef superClass
#undef class
