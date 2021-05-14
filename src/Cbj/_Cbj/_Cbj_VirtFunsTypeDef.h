#ifndef _CBJ_VIRTFUNSTYPEDEF_H
#define _CBJ_VIRTFUNSTYPEDEF_H
#include "_Cbj_VirtFunPtr.h"

#define _Cbj_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr(mFunPrototype) \
    _Cbj_VirtFunPtr mFunPrototype;

#define _Cbj_VirtFunsTypeDef_0(m_cbjType, ...) \
    typedef char m_cbjType##VirtFuns

#define _Cbj_VirtFunsTypeDef__(m_cbjType, ...)                                                    \
    typedef struct m_cbjType##VirtFuns                                                            \
    {                                                                                            \
        _Cbj_Utils_forEach(_Cbj_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr, __VA_ARGS__) \
    } m_cbjType##VirtFuns

#define _Cbj_VirtFunsTypeDef_case(m_cbjType, mCase, ...) \
    _Cbj_VirtFunsTypeDef_##mCase(m_cbjType, __VA_ARGS__)

#define _Cbj_VirtFunsTypeDef(m_cbjType, ...) \
    _Cbj_VirtFunsTypeDef_case(m_cbjType, __VA_ARGS__)

#endif // _CBJ_VIRTFUNSTYPEDEF_H
