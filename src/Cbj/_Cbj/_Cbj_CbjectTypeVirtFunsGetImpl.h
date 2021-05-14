#ifndef _CBJ_CBJECTTYPEVIRTFUNSGETIMPL_H
#define _CBJ_CBJECTTYPEVIRTFUNSGETIMPL_H
#include "_Cbj_CbjectTypeVirtFunsGetFunPrototype.h"

#define _Cbj_CbjectTypeVirtFunsGetImpl(m_cbjType)     \
    _Cbj_CbjectTypeVirtFunsGetFunPrototype(m_cbjType) \
    {                                                 \
        m_cbjType##VirtFuns * virtFuns = NULL;        \
                                                      \
        typedef struct _CbjectType                    \
        {                                             \
            Cbj_Settings_maxAlign x_align;            \
            char const * name;                        \
            CbjectVirtFuns virtFuns;                  \
        } _CbjectType;                                \
                                                      \
        if (((_CbjectType *) meType)->name == NULL)   \
        {                                             \
            virtFuns = &meType->virtFuns;             \
        }                                             \
                                                      \
        return virtFuns;                              \
    }

#endif // _CBJ_CBJECTTYPEVIRTFUNSGETIMPL_H
