#ifndef CBJECT_FUNOVERRIDE_H
#define CBJECT_FUNOVERRIDE_H
#include "Cbject_Utils.h"

#define Cbject_FunOverride_case(className, superClassName, funReturnType, funName, ...) \
    superClassName##Type_virtFuns((superClassName##Type *)&type)->funName = (funReturnType(*)(superClassName * const me))super_##className##_##funName

#define Cbject_FunOverride_caseParams(className, superClassName, funReturnType, funName, ...) \
    superClassName##Type_virtFuns((superClassName##Type *)&type)->funName = (funReturnType(*)(superClassName * const me, __VA_ARGS__))super_##className##_##funName

#define Cbject_FunOverride_switch(className, superClassName, funReturnType, funName, case, ...) \
    Cbject_FunOverride_case##case (className, superClassName, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunOverride_x3(className, superClassName, funReturnType, funName, ...) \
    Cbject_FunOverride_switch(className, superClassName, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunOverride_x2(className, superClassName, funReturnType, funName, funParams) \
    Cbject_FunOverride_x3(className, superClassName, funReturnType, funName, Cbject_Utils_unpack(funParams))

#define Cbject_FunOverride_x(className, superClassName, ...) \
    Cbject_FunOverride_x2(className, superClassName, __VA_ARGS__)

#define Cbject_FunOverride(superClassName, funPrototype) \
    Cbject_FunOverride_x(Type, superClassName, Cbject_Utils_unpack(funPrototype))

#endif // CBJECT_FUNOVERRIDE_H
