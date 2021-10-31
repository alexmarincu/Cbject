#ifndef CBJECT_VIRTFUNSTYPEDEF_H
#define CBJECT_VIRTFUNSTYPEDEF_H
#include "Cbject_VirtFunPtr.h"

#define Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr(funPrototype) \
    Cbject_VirtFunPtr funPrototype;

#define Cbject_VirtFunsTypeDef_void(typeName, ...) \
    typedef char typeName##VirtFuns

#define Cbject_VirtFunsTypeDef_(typeName, ...)                                                       \
    typedef struct typeName##VirtFuns                                                                \
    {                                                                                                \
        Cbject_Utils_forEach(Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr, __VA_ARGS__) \
    } typeName##VirtFuns

#define Cbject_VirtFunsTypeDef_case(typeName, case, ...) \
    Cbject_VirtFunsTypeDef_##case (typeName, __VA_ARGS__)

#define Cbject_VirtFunsTypeDef(typeName, ...) \
    Cbject_VirtFunsTypeDef_case(typeName, __VA_ARGS__)

#endif // CBJECT_VIRTFUNSTYPEDEF_H
