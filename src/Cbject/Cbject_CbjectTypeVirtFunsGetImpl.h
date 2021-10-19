#ifndef CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
#define CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
#include "Cbject_CbjectTypeVirtFunsGetFunPrototype.h"

#define Cbject_CbjectTypeVirtFunsGetImpl(cbjType)     \
    Cbject_CbjectTypeVirtFunsGetFunPrototype(cbjType) \
    {                                                 \
        cbjType##VirtFuns * virtFuns = NULL;          \
                                                      \
        typedef struct ___CbjectType                  \
        {                                             \
            Cbject_Settings_maxAlign ___align;           \
            char const * name;                        \
            CbjectVirtFuns virtFuns;                  \
        } ___CbjectType;                              \
                                                      \
        if (((___CbjectType *) meType)->name == NULL) \
        {                                             \
            virtFuns = &meType->virtFuns;             \
        }                                             \
                                                      \
        return virtFuns;                              \
    }

#endif // CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
