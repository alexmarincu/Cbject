#ifndef SHAPESUPER_H
#define SHAPESUPER_H

#include "../CObject/CObjectSuper.h"
#include "Shape.h"

class_members
_Point origin;
end;

class_virtual_functions
virtual_fun(_UInt32, area);
end;

#endif // SHAPESUPER_H
