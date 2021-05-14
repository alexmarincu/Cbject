#ifndef _CBJ_INITIMPL_H
#define _CBJ_INITIMPL_H
#include "_Cbj_InitFunPrototype.h"
#include "_Cbj_OnInitFunPrototype.h"

#define _Cbj_InitImpl(m_cbjType, mParent)                                 \
    _Cbj_OnInitFunPrototype(m_cbjType, mParent);                          \
    _Cbj_InitFunPrototype(m_cbjType)                                     \
    {                                                                  \
        typedef struct _Cbject                                         \
        {                                                              \
            Cbj_Settings_maxAlign x_align;                                   \
            CbjectType * type;                                            \
            CbjectProps props;                                             \
        } _Cbject;                                                     \
                                                                       \
        mParent##Params s_params;                                       \
        _##m_cbjType##_onInit(me, params, &s_params);                    \
        mParent##_init((mParent *) me, &s_params);                       \
        ((_Cbject *) me)->type = (CbjectType *) m_cbjType##Type_instance(); \
    }                                                                  \
    _Cbj_OnInitFunPrototype(m_cbjType, mParent)

#endif // _CBJ_INITIMPL_H
