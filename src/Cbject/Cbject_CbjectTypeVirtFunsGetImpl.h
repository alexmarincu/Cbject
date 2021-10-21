#ifndef CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
#define CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
#include "Cbject_CbjectTypeVirtFunsGetFunPrototype.h"

#define Cbject_CbjectTypeVirtFunsGetImpl(cbjType)           \
    Cbject_CbjectTypeVirtFunsGetFunPrototype(cbjType)       \
    {                                                       \
        cbjType##VirtFuns * virtFuns = NULL;                \
                                                            \
        typedef struct CbjectTypeContainer                  \
        {                                                   \
            Cbject_Settings_maxAlign a;                     \
            char const * name;                              \
            CbjectVirtFuns virtFuns;                        \
        } CbjectTypeContainer;                              \
                                                            \
        if (((CbjectTypeContainer *) meType)->name == NULL) \
        {                                                   \
            virtFuns = &meType->virtFuns;                   \
        }                                                   \
                                                            \
        return virtFuns;                                    \
    }

#endif // CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
