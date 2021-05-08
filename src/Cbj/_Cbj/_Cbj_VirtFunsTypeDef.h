#ifndef _CBJ_VIRTFUNSTYPEDEF_H
#define _CBJ_VIRTFUNSTYPEDEF_H
#include "_Cbj_Utils.h"
#include "_Cbj_VirtFunPtr.h"

#define _Cbj_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr(funPrototype) \
    _Cbj_VirtFunPtr funPrototype;

#define _Cbj_VirtFunsTypeDef_0(typeName, ...) \
    typedef char typeName##VirtFuns

#define _Cbj_VirtFunsTypeDef__(typeName, ...)                                                    \
    typedef struct typeName##VirtFuns                                                            \
    {                                                                                            \
        _Cbj_Utils_forEach(_Cbj_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr, __VA_ARGS__) \
    } typeName##VirtFuns

#define _Cbj_VirtFunsTypeDef_case(typeName, case, ...) \
    _Cbj_VirtFunsTypeDef_##case (typeName, __VA_ARGS__)

#define _Cbj_VirtFunsTypeDef(typeName, ...) \
    _Cbj_VirtFunsTypeDef_case(typeName, __VA_ARGS__)

#endif // _CBJ_VIRTFUNSTYPEDEF_H
