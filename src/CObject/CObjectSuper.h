#ifndef COBJECTSUPER_H
#define COBJECTSUPER_H

#include "CObject.h"

typedef struct COClass
{
    UInt8 (*objectSize)(CO const * const me);
} COClass;

struct CO
{
    COClass const * thisClass;
};

UInt8 super_CO_objectSize(CO const * const me);

#endif // COBJECTSUPER_H
