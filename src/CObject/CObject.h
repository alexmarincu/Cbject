#ifndef COBJECT_H
#define COBJECT_H
#include "CObjectUtilities.h"

typedef struct CObject CObject;

Void CObject_init(CObject * const me);
UInt8 CObject_objectSize(CObject const * const me);

#endif // COBJECT_H
