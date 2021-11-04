#ifndef CBJECT_NEWOBJECTIMPL_H
#define CBJECT_NEWOBJECTIMPL_H
#include "Cbject_NewObjectFunPrototype.h"
#include <assert.h>
#include <stdlib.h>

#define Cbject_NewObjectImpl(typeName)                           \
    Cbject_NewObjectFunPrototype(typeName)                       \
    {                                                            \
        typeName * me = (typeName *)malloc(sizeof(typeName));    \
        assert((me != NULL) && "Heap memory allocation failed"); \
        memset(me, 0, sizeof(typeName));                         \
        typeName##_init(me, params);                             \
        return me;                                               \
    }

#endif // CBJECT_NEWOBJECTIMPL_H
