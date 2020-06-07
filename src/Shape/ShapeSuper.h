#ifndef SHAPESUPER_H
#define SHAPESUPER_H
#include "../CObject/CObjectSuper.h"
#include "../Primitives.h"
#include "Shape.h"

CLASS_MEMBERS(Shape)
_Point origin;
END;

CLASS_VIRTUAL_METHODS(Shape)
_UInt32(Ref area)(Shape me);
END;

#endif // SHAPESUPER_H
