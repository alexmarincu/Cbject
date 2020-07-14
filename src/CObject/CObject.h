#ifndef COBJECT_H
#define COBJECT_H
#include "CObjectUtilities.h"

typedef struct CO CO;

Void CO_init(CO * const me);
UInt8 CO_objectSize(CO const * const me);

#endif // COBJECT_H
