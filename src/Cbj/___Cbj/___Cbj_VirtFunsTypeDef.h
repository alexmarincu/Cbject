#ifndef _CBJ_VIRTFUNSTYPEDEF_H
#define _CBJ_VIRTFUNSTYPEDEF_H
#include "___Cbj_VirtFunPtr.h"

#define ___Cbj_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr(funPrototype) \
    ___Cbj_VirtFunPtr funPrototype;

#define ___Cbj_VirtFunsTypeDef_0(cbjType, ...) \
    typedef char cbjType##VirtFuns

#define ___Cbj_VirtFunsTypeDef_(cbjType, ...)                                                       \
    typedef struct cbjType##VirtFuns                                                                 \
    {                                                                                                \
        ___Cbj_Utils_forEach(___Cbj_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr, __VA_ARGS__) \
    } cbjType##VirtFuns

#define ___Cbj_VirtFunsTypeDef_case(cbjType, case, ...) \
    ___Cbj_VirtFunsTypeDef_##case (cbjType, __VA_ARGS__)

#define ___Cbj_VirtFunsTypeDef(cbjType, ...) \
    ___Cbj_VirtFunsTypeDef_case(cbjType, __VA_ARGS__)

#endif // _CBJ_VIRTFUNSTYPEDEF_H
