#ifndef CBJECT_BINDFUNS_H
#define CBJECT_BINDFUNS_H
#include "Cbject_Utils.h"

#define Cbject_BindFun_void(typeName, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *)&t)->funName = (returnType(*)(parent * const me))typeName##_s_##funName

#define Cbject_BindFun_(typeName, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *)&t)->funName = (returnType(*)(parent * const me, __VA_ARGS__))typeName##_s_##funName

#define Cbject_BindFun_case(typeName, parent, returnType, funName, case, ...) \
    Cbject_BindFun_##case (typeName, parent, returnType, funName, __VA_ARGS__)

#define Cbject_BindFun__(typeName, parent, returnType, funName, ...) \
    Cbject_BindFun_case(typeName, parent, returnType, funName, __VA_ARGS__)

#define Cbject_BindFun(parent, returnType, funName, params) \
    Cbject_BindFun__(Type, parent, returnType, funName, Cbject_Utils_stripParentheses(params))

#endif // CBJECT_BINDFUNS_H
