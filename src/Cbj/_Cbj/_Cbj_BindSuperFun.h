#ifndef _CBJ_BINDSUPERFUN_H
#define _CBJ_BINDSUPERFUN_H
#include "_Cbj_Utils.h"

#define _Cbj_BindSuperFun_0(cbjType, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *) &type)->funName = (returnType(*)(parent * const me)) s_##cbjType##_##funName

#define _Cbj_BindSuperFun__(cbjType, parent, returnType, funName, ...) \
    parent##Type_virtFuns((parent##Type *) &type)->funName = (returnType(*)(parent * const me, __VA_ARGS__)) s_##cbjType##_##funName

#define _Cbj_BindSuperFun_case(cbjType, parent, returnType, funName, case, ...) \
    _Cbj_BindSuperFun_##case(cbjType, parent, returnType, funName, __VA_ARGS__)

#define _Cbj_BindSuperFun_(cbjType, parent, returnType, funName, ...) \
    _Cbj_BindSuperFun_case(cbjType, parent, returnType, funName, __VA_ARGS__)

#define _Cbj_BindSuperFun(parent, returnType, funName, args) \
    _Cbj_BindSuperFun_(Type, parent, returnType, funName, _Cbj_Utils_stripParentheses(args))

#endif // _CBJ_BINDSUPERFUN_H
