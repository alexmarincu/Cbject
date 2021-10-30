#ifndef CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
#define CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
#include "Cbject_CbjectTypeVirtFunsGetFunPrototype.h"

#define Cbject_CbjectTypeVirtFunsGetImpl(typeName)     \
    Cbject_CbjectTypeVirtFunsGetFunPrototype(typeName) \
    {                                                  \
        typeName##VirtFuns * virtFuns = NULL;          \
                                                       \
        typedef struct CbjectTypeT                     \
        {                                              \
            Cbject_Settings_maxAlign a;                \
            char const * name;                         \
            CbjectType * st;                           \
            CbjectVirtFuns vf;                         \
        } CbjectTypeT;                                 \
                                                       \
        if (((CbjectTypeT *) meType)->name == NULL)    \
        {                                              \
            virtFuns = &meType->vf;                    \
        }                                              \
                                                       \
        return virtFuns;                               \
    }

#endif // CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
