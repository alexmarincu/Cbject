#ifndef CBJECT_NEWOBJECTIMPL_H
#define CBJECT_NEWOBJECTIMPL_H
#include "Cbject_NewObjectFunPrototype.h"
#include <assert.h>
#include <stdlib.h>

/*
Cbject_NewObjectImpl
*/
#define Cbject_NewObjectImpl(className)                          \
    Cbject_NewObjectFunPrototype(className)                      \
    {                                                            \
        className * me = (className *)malloc(sizeof(className)); \
        assert((me != NULL) && "Heap memory allocation failed"); \
        memset(me, 0, sizeof(className));                        \
        className##_init(me, params);                            \
        return me;                                               \
    }

#endif // CBJECT_NEWOBJECTIMPL_H
