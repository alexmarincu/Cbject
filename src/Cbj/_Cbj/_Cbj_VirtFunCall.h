#ifndef _CBJ_VIRTFUNCALL_H
#define _CBJ_VIRTFUNCALL_H
#include "_Cbj_Utils.h"

#define _Cbj_VirtFunCall_0(m_cbjType, mFunName, ...) \
    typedef struct _Cbject                        \
    {                                             \
        Cbj_Settings_maxAlign x_align;                  \
        CbjectType * type;                           \
        CbjectProps props;                            \
    } _Cbject;                                    \
                                                  \
    return ((m_cbjType##Type *) ((_Cbject *) me)->type)->virtFuns.mFunName(me)

#define _Cbj_VirtFunCall__(m_cbjType, mFunName, ...) \
    typedef struct _Cbject                        \
    {                                             \
        Cbj_Settings_maxAlign x_align;                  \
        CbjectType * type;                           \
        CbjectProps props;                            \
    } _Cbject;                                    \
                                                  \
    return ((m_cbjType##Type *) ((_Cbject *) me)->type)->virtFuns.mFunName(me, __VA_ARGS__)

#define _Cbj_VirtFunCall_case(m_cbjType, mFunName, mCase, ...) \
    _Cbj_VirtFunCall_##mCase (m_cbjType, mFunName, __VA_ARGS__)

#define _Cbj_VirtFunCall(m_cbjType, mFunName, ...) \
    _Cbj_VirtFunCall_case(m_cbjType, mFunName, __VA_ARGS__)

#endif // _CBJ_VIRTFUNCALL_H
