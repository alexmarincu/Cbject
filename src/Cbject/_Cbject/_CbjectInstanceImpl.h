#ifndef _CBJECTINSTANCEIMPL_H
#define _CBJECTINSTANCEIMPL_H
#include "_CbjectInstanceFunPrototype.h"

#define _CbjectInstanceImpl(cbjectTypeName)                                             \
    _CbjectInstanceFunPrototype(cbjectTypeName)                                    \
    {                                                                              \
        static cbjectTypeName me;                                                       \
        if (Cbject_CbjectType((Cbject *) &me) == NULL) { cbjectTypeName##_init(&me, NULL); } \
        return &me;                                                                \
    }

#endif // _CBJECTINSTANCEIMPL_H
