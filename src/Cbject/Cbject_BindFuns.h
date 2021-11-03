#ifndef CBJECT_BINDFUNS_H
#define CBJECT_BINDFUNS_H
#include "Cbject_Utils.h"

#define Cbject_BindFun_case_paramsNone(typeName, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *)&t)->funName = (returnType(*)(parent * const me))typeName##_s_##funName

#define Cbject_BindFun_case_params(typeName, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *)&t)->funName = (returnType(*)(parent * const me, __VA_ARGS__))typeName##_s_##funName

#define Cbject_BindFun_switch(typeName, parent, returnType, funName, case, ...) \
    Cbject_BindFun_case_##case (typeName, parent, returnType, funName, __VA_ARGS__)

#define Cbject_BindFun_xxx(typeName, parent, returnType, funName, ...) \
    Cbject_BindFun_switch(typeName, parent, returnType, funName, __VA_ARGS__)

#define Cbject_BindFun_xx(typeName, parent, returnType, funName, params) \
    Cbject_BindFun_xxx(typeName, parent, returnType, funName, Cbject_Utils_stripParentheses(params))

#define Cbject_BindFun_x(typeName, parent, ...) \
    Cbject_BindFun_xx(typeName, parent, __VA_ARGS__)

#define Cbject_BindFun(parent, funPrototype) \
    Cbject_BindFun_x(Type, parent, Cbject_Utils_stripParentheses(funPrototype))

#endif // CBJECT_BINDFUNS_H
