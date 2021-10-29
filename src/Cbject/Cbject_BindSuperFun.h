#ifndef CBJECT_BINDSUPERFUN_H
#define CBJECT_BINDSUPERFUN_H
#include "Cbject_Utils.h"

#define Cbject_BindSuperFun_0(typeName, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *) &t)->funName = (returnType(*)(parent * const me)) super_##typeName##_##funName

#define Cbject_BindSuperFun_(typeName, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *) &t)->funName = (returnType(*)(parent * const me, __VA_ARGS__)) super_##typeName##_##funName

#define Cbject_BindSuperFun_case(typeName, parent, returnType, funName, case, ...) \
    Cbject_BindSuperFun_##case (typeName, parent, returnType, funName, __VA_ARGS__)

#define Cbject_BindSuperFun__(typeName, parent, returnType, funName, ...) \
    Cbject_BindSuperFun_case(typeName, parent, returnType, funName, __VA_ARGS__)

#define Cbject_BindSuperFun(parent, returnType, funName, params) \
    Cbject_BindSuperFun__(Type, parent, returnType, funName, Cbject_Utils_stripParentheses(params))

#endif // CBJECT_BINDSUPERFUN_H
