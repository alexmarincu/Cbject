#ifndef COBJECT_H
#define COBJECT_H

#include "CObjectUtilities.h"

typedef struct CObject _ptr __CObject;
typedef struct CObject ptr _CObject;
typedef struct CObject const ptr CObject;

Void CObject_init(_CObject me);
Void CObject_reset(_CObject me);
_UInt8 CObject_objectSize(CObject me);
_Boolean CObject_isInitialized(CObject me);

#endif // COBJECT_H
