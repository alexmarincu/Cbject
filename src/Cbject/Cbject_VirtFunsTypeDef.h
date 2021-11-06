#ifndef CBJECT_VIRTFUNSTYPEDEF_H
#define CBJECT_VIRTFUNSTYPEDEF_H
#include "Cbject_VirtFunPtr.h"

#define Cbject_VirtFunsTypeDef_case_(typeName, ...) \
    typedef char typeName##VirtFuns

#define Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr_case_Implemented(funPrototype) \
    Cbject_VirtFunPtr funPrototype;

#define Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr_case_Pure(funPrototype) \
    Cbject_VirtFunPtr funPrototype;

#define Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr_switch(funPrototype, case) \
    Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr_case_##case (funPrototype)

#define Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr_x1(...) \
    Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr_switch(__VA_ARGS__)

#define Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr(funPrototype) \
    Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr_x1(Cbject_Utils_stripParentheses(funPrototype))

#define Cbject_VirtFunsTypeDef_case_virtFuns(typeName, ...)                                          \
    typedef struct typeName##VirtFuns                                                                \
    {                                                                                                \
        Cbject_Utils_forEach(Cbject_VirtFunsTypeDef_stripParenthesesAndApplyVirtFunPtr, __VA_ARGS__) \
    } typeName##VirtFuns

#define Cbject_VirtFunsTypeDef_switch(typeName, case, ...) \
    Cbject_VirtFunsTypeDef_case_##case (typeName, __VA_ARGS__)

#define Cbject_VirtFunsTypeDef_x1(typeName, ...) \
    Cbject_VirtFunsTypeDef_switch(typeName, __VA_ARGS__)

#define Cbject_VirtFunsTypeDef(typeName, virtFuns) \
    Cbject_VirtFunsTypeDef_x1(typeName, Cbject_Utils_stripParentheses(virtFuns))

#endif // CBJECT_VIRTFUNSTYPEDEF_H
