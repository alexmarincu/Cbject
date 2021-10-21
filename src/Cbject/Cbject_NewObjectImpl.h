#ifndef CBJECT_NEWOBJECTIMPL_H
#define CBJECT_NEWOBJECTIMPL_H
#include "Cbject_NewObjectFunPrototype.h"

#define Cbject_NewObjectImpl(cbjType)                            \
    Cbject_NewObjectFunPrototype(cbjType)                        \
    {                                                            \
        cbjType * me = (cbjType *) malloc(sizeof(cbjType));      \
        assert((me != NULL) && "Heap memory allocation failed"); \
        memset(me, 0, sizeof(cbjType));                          \
        cbjType##_init(me, params);                              \
        return me;                                               \
    }

#endif // CBJECT_NEWOBJECTIMPL_H
