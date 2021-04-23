#include "Rectangle.h"
#include "../Shape/Shape.h"

#define klass Rectangle
#define superKlass Shape

PoolSize(10);

SuperFunction(float, area, (0));
KlassSetup({ BindFunction(float, Shape, area, ()); });
DefaultSetters(
    (uint32, width),
    (uint32, height));

DefaultGetters(
    (uint32, width),
    (uint32, height));

Init({
    superInitParams =
        (ShapeInitParams){
            .origin.x = params->origin.x,
            .origin.y = params->origin.y};

    me->m.width = params->width;
    me->m.height = params->height;
});

Terminate({});
Function(uint32, test, (_, uint32 const a)) { return a; }
SuperFunction(float, area, (0)) { return me->m.width * me->m.height; }

#undef superKlass
#undef klass
