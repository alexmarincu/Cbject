#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Primitives.h"
#include "../Shape/Shape.h"

#undef CLASS_NAME
#define CLASS_NAME Rectangle
#undef SUPER_CLASS_NAME
#define SUPER_CLASS_NAME Shape

CLASS_EXTENSION_INIT_PARAMS
UInt32 width;
UInt32 height;
END;

#endif // RECTANGLE_H
