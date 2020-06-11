#ifndef SHAPE_H
#define SHAPE_H

#include "../CObject/CObject.h"
#include "Point.h"

#undef CLASS_NAME
#define CLASS_NAME Shape

ABSTRACT_CLASS_INIT_PARAMS
Point origin;
end;

set_get(Point, origin);

fun(_UInt32, area);

#endif // SHAPE_H
