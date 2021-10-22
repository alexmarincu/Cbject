#ifndef CBJECT_BINDSUPERFUN_H
#define CBJECT_BINDSUPERFUN_H
#include "Cbject_Utils.h"

#define Cbject_BindSuperFun_0(cbjType, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *) &type)->funName = (returnType(*)(parent * const me)) super_##cbjType##_##funName

#define Cbject_BindSuperFun_(cbjType, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *) &type)->funName = (returnType(*)(parent * const me, __VA_ARGS__)) super_##cbjType##_##funName

#define Cbject_BindSuperFun_case(cbjType, parent, returnType, funName, case, ...) \
    Cbject_BindSuperFun_##case (cbjType, parent, returnType, funName, __VA_ARGS__)

#define Cbject_BindSuperFun__(cbjType, parent, returnType, funName, ...) \
    Cbject_BindSuperFun_case(cbjType, parent, returnType, funName, __VA_ARGS__)

#define Cbject_BindSuperFun(parent, returnType, funName, args) \
    Cbject_BindSuperFun__(Type, parent, returnType, funName, Cbject_Utils_stripParentheses(args))

#endif // CBJECT_BINDSUPERFUN_H
