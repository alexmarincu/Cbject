#ifndef CBJECT_BINDFUNS_H
#define CBJECT_BINDFUNS_H
#include "Cbject_Utils.h"

#define Cbject_BindFun_case(typeName, superTypeName, funReturnType, funName, ...) \
    superTypeName##Type_virtFuns((superTypeName##Type *)&type)->funName = (funReturnType(*)(superTypeName * const me))super_##typeName##_##funName

#define Cbject_BindFun_caseParams(typeName, superTypeName, funReturnType, funName, ...) \
    superTypeName##Type_virtFuns((superTypeName##Type *)&type)->funName = (funReturnType(*)(superTypeName * const me, __VA_ARGS__))super_##typeName##_##funName

#define Cbject_BindFun_switch(typeName, superTypeName, funReturnType, funName, case, ...) \
    Cbject_BindFun_case##case (typeName, superTypeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_BindFun_x3(typeName, superTypeName, funReturnType, funName, ...) \
    Cbject_BindFun_switch(typeName, superTypeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_BindFun_x2(typeName, superTypeName, funReturnType, funName, funParams) \
    Cbject_BindFun_x3(typeName, superTypeName, funReturnType, funName, Cbject_Utils_unpack(funParams))

#define Cbject_BindFun_x(typeName, superTypeName, ...) \
    Cbject_BindFun_x2(typeName, superTypeName, __VA_ARGS__)

#define Cbject_BindFun(superTypeName, funPrototype) \
    Cbject_BindFun_x(Type, superTypeName, Cbject_Utils_unpack(funPrototype))

#endif // CBJECT_BINDFUNS_H
