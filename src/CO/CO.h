#ifndef CO_H
#define CO_H
#include "COUtilities.h"

typedef struct CO CO;
Void CO_init(CO * const _this);
UInt8 CO_objectSize(CO const * const _this);
char const * CO_classType(CO const * const _this);
UInt8 CO_classSize();

#endif // CO_H
