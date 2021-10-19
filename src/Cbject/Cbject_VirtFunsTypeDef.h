#ifndef CBJECT_VIRTFUNSTYPEDEF_H
#define CBJECT_VIRTFUNSTYPEDEF_H
#include "Cbject_VirtFunPtr.h"

#define Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr(funPrototype) \
    Cbject_VirtFunPtr funPrototype;

#define Cbject_VirtFunsTypeDef_0(cbjType, ...) \
    typedef char cbjType##VirtFuns

#define Cbject_VirtFunsTypeDef_(cbjType, ...)                                                        \
    typedef struct cbjType##VirtFuns                                                                 \
    {                                                                                                \
        Cbject_Utils_forEach(Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr, __VA_ARGS__) \
    } cbjType##VirtFuns

#define Cbject_VirtFunsTypeDef_case(cbjType, case, ...) \
    Cbject_VirtFunsTypeDef_##case (cbjType, __VA_ARGS__)

#define Cbject_VirtFunsTypeDef(cbjType, ...) \
    Cbject_VirtFunsTypeDef_case(cbjType, __VA_ARGS__)

#endif // CBJECT_VIRTFUNSTYPEDEF_H
