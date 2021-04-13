#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Shape.h"

#define class Circle
#define superClass Shape

publicConstant(float, pi);
publicConstants((float, anotherPi));

ClassInitParams(
    uint32 const radius);

    #define CircleMembers \
uint32 radius

classDeclaration(CircleMembers);



setterGetter(uint32, radius);

overrideFunctions(
    (float, Shape, area, ()),
    (void, Shape, draw, (uint8 const a)));

virtualFunctions((void, rotate, ()));

functions((void, rotate, ()));

#undef class
#undef superClass
#endif // CIRCLE_H
