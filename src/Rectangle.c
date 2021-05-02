#include "Rectangle.h"
#include "Shape.h"

#define klass Rectangle
#define superKlass Shape
PoolSize(10);
SuperFunction(float, area, (0));
KlassSetup({ BindFunction(float, Shape, area, ()); });

DefaultSetters(_,
    (uint32, width),
    (uint32, height));

DefaultGetters(_,
    (uint32, width),
    (uint32, height));

Init({
    superParams =
        (ShapeParams){
            .origin.x = params->origin.x,
            .origin.y = params->origin.y};

    me->p.width = params->width;
    me->p.height = params->height;
});

Terminate({});
Function(uint32, test, (_, uint32 const a)) { return a; }
SuperFunction(float, area, (0)) { return me->p.width * me->p.height; }

#undef superKlass
#undef klass
