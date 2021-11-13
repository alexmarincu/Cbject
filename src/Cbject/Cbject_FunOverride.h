#ifndef CBJECT_FUNOVERRIDE_H
#define CBJECT_FUNOVERRIDE_H
#include "Cbject_Utils.h"

/*
Cbject_FunOverride_Prototype
*/
#define Cbject_FunOverride_Prototype_caseNA(class, funReturnType, funName, ...) \
    funReturnType super##class##_##funName(class * const me)

#define Cbject_FunOverride_Prototype_caseParams(class, funReturnType, funName, ...) \
    funReturnType super##class##_##funName(class * const me, __VA_ARGS__)

#define Cbject_FunOverride_Prototype_x1(class, funReturnType, funName, paramsCase, ...) \
    Cbject_FunOverride_Prototype_case##paramsCase(class, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunOverride_Prototype_x0(class, funReturnType, funName, ...) \
    Cbject_FunOverride_Prototype_x1(class, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunOverride_Prototype(class, funReturnType, funName, funParamsPack) \
    Cbject_FunOverride_Prototype_x0(class, funReturnType, funName, Cbject_Utils_unpack(funParamsPack))

/*
Cbject_FunOverride
*/
#define Cbject_FunOverride_caseNA(class, superClass, funReturnType, funName, ...) \
    superClass##Type_virtFuns((superClass##Type *)&type)->funName = (funReturnType(*)(superClass * const me))super##class##_##funName

#define Cbject_FunOverride_caseParams(class, superClass, funReturnType, funName, ...) \
    superClass##Type_virtFuns((superClass##Type *)&type)->funName = (funReturnType(*)(superClass * const me, __VA_ARGS__))super##class##_##funName

#define Cbject_FunOverride_x3(class, superClass, funReturnType, funName, paramsCase, ...) \
    Cbject_FunOverride_case##paramsCase(class, superClass, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunOverride_x2(class, superClass, funReturnType, funName, ...) \
    Cbject_FunOverride_x3(class, superClass, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunOverride_x1(class, superClass, funReturnType, funName, funParamsPack) \
    Cbject_FunOverride_x2(class, superClass, funReturnType, funName, Cbject_Utils_unpack(funParamsPack))

#define Cbject_FunOverride_x0(class, superClass, ...) \
    Cbject_FunOverride_x1(class, superClass, __VA_ARGS__)

#define Cbject_FunOverride(class, superClass, funPrototypePack) \
    Cbject_FunOverride_x0(class, superClass, Cbject_Utils_unpack(funPrototypePack))

#endif // CBJECT_FUNOVERRIDE_H
