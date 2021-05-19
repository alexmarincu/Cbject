#ifndef ___CBJ_BINDSUPERFUN_H
#define ___CBJ_BINDSUPERFUN_H
#include "___Cbj_Utils.h"

#define ___Cbj_BindSuperFun_0(cbjType, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *) &type)->funName = (returnType(*)(parent * const me)) s_##cbjType##_##funName

#define ___Cbj_BindSuperFun__(cbjType, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *) &type)->funName = (returnType(*)(parent * const me, __VA_ARGS__)) s_##cbjType##_##funName

#define ___Cbj_BindSuperFun_case(cbjType, parent, returnType, funName, case, ...) \
    ___Cbj_BindSuperFun_##case (cbjType, parent, returnType, funName, __VA_ARGS__)

#define ___Cbj_BindSuperFun_(cbjType, parent, returnType, funName, ...) \
    ___Cbj_BindSuperFun_case(cbjType, parent, returnType, funName, __VA_ARGS__)

#define ___Cbj_BindSuperFun(parent, returnType, funName, args) \
    ___Cbj_BindSuperFun_(Type, parent, returnType, funName, ___Cbj_Utils_stripParentheses(args))

#endif // ___CBJ_BINDSUPERFUN_H
