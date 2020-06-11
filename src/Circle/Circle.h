#ifndef CIRCLE_H
#define CIRCLE_H

#include "../Shape/Shape.h"

#undef CLASS_NAME
#define CLASS_NAME Circle
#undef SUPER_CLASS_NAME
#define SUPER_CLASS_NAME Shape

CLASS_EXTENSION_INIT_PARAMS
UInt32 radius;
end;

set_get(UInt32, radius);

#endif // CIRCLE_H
