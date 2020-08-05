#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Point.h"

#define Class_ Circle

public_constant(Float, pi);
public_constants((Float, anotherPi));

class_init_params(
    Point const origin,
    UInt32 const radius);

set_get(UInt32, radius);
fun(Void, rotate, ());

#undef Class_

#endif // CIRCLE_H
