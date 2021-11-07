#ifndef CBJECT_FUNOVERRIDE_H
#define CBJECT_FUNOVERRIDE_H
#include "Cbject_Utils.h"

/*
Cbject_FunOverride_Prototype
*/
#define Cbject_FunOverride_Prototype_caseNA(className, funReturnType, funName, ...) \
    funReturnType super_##className##_##funName(className * const me)

#define Cbject_FunOverride_Prototype_caseParams(className, funReturnType, funName, ...) \
    funReturnType super_##className##_##funName(className * const me, __VA_ARGS__)

#define Cbject_FunOverride_Prototype_x1(className, funReturnType, funName, case, ...) \
    Cbject_FunOverride_Prototype_case##case (className, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunOverride_Prototype_x0(className, funReturnType, funName, ...) \
    Cbject_FunOverride_Prototype_x1(className, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunOverride_Prototype(className, funReturnType, funName, funParams) \
    Cbject_FunOverride_Prototype_x0(className, funReturnType, funName, Cbject_Utils_unpack(funParams))

/*
Cbject_FunOverride
*/
#define Cbject_FunOverride_caseNA(className, superClassName, funReturnType, funName, ...) \
    superClassName##Type_virtFuns((superClassName##Type *)&type)->funName = (funReturnType(*)(superClassName * const me))super_##className##_##funName

#define Cbject_FunOverride_caseParams(className, superClassName, funReturnType, funName, ...) \
    superClassName##Type_virtFuns((superClassName##Type *)&type)->funName = (funReturnType(*)(superClassName * const me, __VA_ARGS__))super_##className##_##funName

#define Cbject_FunOverride_x3(className, superClassName, funReturnType, funName, case, ...) \
    Cbject_FunOverride_case##case (className, superClassName, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunOverride_x2(className, superClassName, funReturnType, funName, ...) \
    Cbject_FunOverride_x3(className, superClassName, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunOverride_x1(className, superClassName, funReturnType, funName, funParams) \
    Cbject_FunOverride_x2(className, superClassName, funReturnType, funName, Cbject_Utils_unpack(funParams))

#define Cbject_FunOverride_x0(className, superClassName, ...) \
    Cbject_FunOverride_x1(className, superClassName, __VA_ARGS__)

#define Cbject_FunOverride(className, superClassName, funPrototype) \
    Cbject_FunOverride_x0(className, superClassName, Cbject_Utils_unpack(funPrototype))

#endif // CBJECT_FUNOVERRIDE_H
