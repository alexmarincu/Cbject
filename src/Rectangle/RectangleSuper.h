#ifndef RECTANGLESUPER_H
#define RECTANGLESUPER_H
#include "../Primitives.h"
#include "../Shape/ShapeSuper.h"
#include "Rectangle.h"

CLASS_EXTENSION_MEMBERS(Rectangle, Shape)
_UInt32 width;
_UInt32 height;
END;

CLASS_EXTENSION_VIRTUAL_METHODS(Rectangle, Shape)
END;

#endif // RECTANGLESUPER_H
