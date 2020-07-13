#ifndef POINT_H
#define POINT_H
#include "../CObject/CObject.h"

#undef Class
#define Class Point

data_class_members(
    UInt32 x,
    UInt32 y);

#endif // POINT_H
