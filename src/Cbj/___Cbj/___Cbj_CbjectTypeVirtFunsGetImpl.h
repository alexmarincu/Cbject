#ifndef ___CBJ_CBJECTTYPEVIRTFUNSGETIMPL_H
#define ___CBJ_CBJECTTYPEVIRTFUNSGETIMPL_H
#include "___Cbj_CbjectTypeVirtFunsGetFunPrototype.h"

#define ___Cbj_CbjectTypeVirtFunsGetImpl(cbjType)     \
    ___Cbj_CbjectTypeVirtFunsGetFunPrototype(cbjType) \
    {                                                 \
        cbjType##VirtFuns * virtFuns = NULL;          \
                                                      \
        typedef struct ___CbjectType                  \
        {                                             \
            Cbj_Settings_maxAlign ___align;           \
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

#endif // ___CBJ_CBJECTTYPEVIRTFUNSGETIMPL_H
