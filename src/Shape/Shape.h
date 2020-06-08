#ifndef SHAPE_H
#define SHAPE_H
#include "../CObject/CObject.h"
#include "../Primitives.h"
#include "Point.h"

#undef CLASS_NAME
#define CLASS_NAME Shape

ABSTRACT_CLASS_INIT_PARAMS
Point origin;
END;


/**
 * Getters and Setters
 */
Void Shape_setOrigin(_Shape me, Point origin);
_Point Shape_getOrigin(Shape me);

/**
 * Methods
 */
_UInt32 Shape_area(Shape me);

#endif // SHAPE_H
