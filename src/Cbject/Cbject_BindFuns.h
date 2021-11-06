#ifndef CBJECT_BINDFUNS_H
#define CBJECT_BINDFUNS_H
#include "Cbject_Utils.h"

#define Cbject_BindFun_case(className, superClassName, funReturnType, funName, ...) \
    superClassName##Type_virtFuns((superClassName##Type *)&type)->funName = (funReturnType(*)(superClassName * const me))super_##className##_##funName

#define Cbject_BindFun_caseParams(className, superClassName, funReturnType, funName, ...) \
    superClassName##Type_virtFuns((superClassName##Type *)&type)->funName = (funReturnType(*)(superClassName * const me, __VA_ARGS__))super_##className##_##funName

#define Cbject_BindFun_switch(className, superClassName, funReturnType, funName, case, ...) \
    Cbject_BindFun_case##case (className, superClassName, funReturnType, funName, __VA_ARGS__)

#define Cbject_BindFun_x3(className, superClassName, funReturnType, funName, ...) \
    Cbject_BindFun_switch(className, superClassName, funReturnType, funName, __VA_ARGS__)

#define Cbject_BindFun_x2(className, superClassName, funReturnType, funName, funParams) \
    Cbject_BindFun_x3(className, superClassName, funReturnType, funName, Cbject_Utils_unpack(funParams))

#define Cbject_BindFun_x(className, superClassName, ...) \
    Cbject_BindFun_x2(className, superClassName, __VA_ARGS__)

#define Cbject_BindFun(superClassName, funPrototype) \
    Cbject_BindFun_x(Type, superClassName, Cbject_Utils_unpack(funPrototype))

#endif // CBJECT_BINDFUNS_H
