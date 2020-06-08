#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Primitives.h"
#include "../Shape/Shape.h"

#undef CLASS_NAME
#define CLASS_NAME Circle
#undef SUPER_CLASS_NAME
#define SUPER_CLASS_NAME Shape

CLASS_EXTENSION_INIT_PARAMS
UInt32 radius;
END;

#endif // CIRCLE_H
