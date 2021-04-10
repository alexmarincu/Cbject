#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Shape.h"

#define class Circle
#define superClass Shape

publicConstant(float, pi);
publicConstants((float, anotherPi));

classParams(
    Point const origin,
    uint32 const radius);

    #define CircleMembers \
uint32 radius

classDeclaration(CircleMembers);
    // enum{CircleClass_sizes = sizeof(struct{uint8 _[ShapeClass_sizes]; uint32 radius;})};

setterGetter(uint32, radius);
function(void, rotate, ());

#undef class
#undef superClass
#endif // CIRCLE_H
