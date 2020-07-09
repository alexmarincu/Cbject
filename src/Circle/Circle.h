#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Shape/Shape.h"

#undef class
#define class Circle

public_constant(Float, pi);
public_constants((Float, anotherPi));

class_init_params(
    Point const origin,
    UInt32 const radius);

class_pool_size(10);

set_get(UInt32, radius);

#endif // CIRCLE_H
