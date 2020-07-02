#ifndef COLOR_H
#define COLOR_H
#include "../CObject/CObject.h"

#undef class
#define class Color

enum_class_values(
    enum_val(red),
    enum_val(yellow),
    enum_val(blue) = 5);

#endif // COLOR_H
