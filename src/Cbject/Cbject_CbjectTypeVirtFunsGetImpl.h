#ifndef CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
#define CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
#include "Cbject_CbjectTypeVirtFunsGetFunPrototype.h"

#define Cbject_CbjectTypeVirtFunsGetImpl(typeName)          \
    Cbject_CbjectTypeVirtFunsGetFunPrototype(typeName)      \
    {                                                       \
        typeName##VirtFuns * virtFuns = NULL;               \
                                                            \
        typedef struct CbjectTypeContainer                  \
        {                                                   \
            Cbject_Settings_maxAlign a;                     \
            char const * name;                              \
            CbjectVirtFuns vf;                              \
        } CbjectTypeContainer;                              \
                                                            \
        if (((CbjectTypeContainer *) meType)->name == NULL) \
        {                                                   \
            virtFuns = &meType->vf;                         \
        }                                                   \
                                                            \
        return virtFuns;                                    \
    }

#endif // CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
