#ifndef COLOR_H
#define COLOR_H
#include "../CObject/CObject.h"

#undef class
#define class Color

enum_class_members(
    enum_member(red),
    enum_member(yellow),
    enum_member(blue) = 5);

#endif // COLOR_H
