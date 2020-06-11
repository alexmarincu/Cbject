#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Shape/Shape.h"

#undef CLASS_NAME
#define CLASS_NAME Rectangle
#undef SUPER_CLASS_NAME
#define SUPER_CLASS_NAME Shape

CLASS_EXTENSION_INIT_PARAMS
UInt32 width;
UInt32 height;
end;

set_get(UInt32, width);
set_get(UInt32, height);
fun(_UInt32, test, UInt32 a);

#endif // RECTANGLE_H
