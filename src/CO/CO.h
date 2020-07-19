#ifndef CO_H
#define CO_H
#include "COUtilities.h"

typedef struct CO CO;

Void CO_init(CO * const this_);
UInt8 CO_objectSize(CO const * const this_);
char const * CO_classType(CO const * const this_);
UInt8 COClass_size();

#endif // CO_H
