#ifndef _CBJ_VIRTFUNSTYPEDEF_H
#define _CBJ_VIRTFUNSTYPEDEF_H
#include "_Cbj_VirtFunPtr.h"

#define _Cbj_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr(funPrototype) \
    _Cbj_VirtFunPtr funPrototype;

#define _Cbj_VirtFunsTypeDef_0(cbjType, ...) \
    typedef char cbjType##VirtFuns

#define _Cbj_VirtFunsTypeDef__(cbjType, ...)                                                    \
    typedef struct cbjType##VirtFuns                                                            \
    {                                                                                            \
        _Cbj_Utils_forEach(_Cbj_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr, __VA_ARGS__) \
    } cbjType##VirtFuns

#define _Cbj_VirtFunsTypeDef_case(cbjType, case, ...) \
    _Cbj_VirtFunsTypeDef_##case(cbjType, __VA_ARGS__)

#define _Cbj_VirtFunsTypeDef(cbjType, ...) \
    _Cbj_VirtFunsTypeDef_case(cbjType, __VA_ARGS__)

#endif // _CBJ_VIRTFUNSTYPEDEF_H
