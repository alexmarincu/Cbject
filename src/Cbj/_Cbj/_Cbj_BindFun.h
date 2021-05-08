#ifndef _CBJ_BINDFUN_H
#define _CBJ_BINDFUN_H

#define _Cbj_BindFun_0(cbjType, returnType, parent, funName, ...) \
    ((parent##Class *) &c)->vf.funName = (returnType(*)(parent * const me)) s_##cbjType##_##funName

#define _Cbj_BindFun__(cbjType, returnType, parent, funName, ...) \
    ((parent##Class *) &c)->vf.funName = (returnType(*)(parent * const me, __VA_ARGS__)) s_##cbjType##_##funName

#define _Cbj_BindFun_case(cbjType, returnType, parent, funName, case, ...) \
    _Cbj_BindFun_##case (cbjType, returnType, parent, funName, __VA_ARGS__)

#define _Cbj_BindFun_(cbjType, returnType, parent, funName, ...) \
    _Cbj_BindFun_case(cbjType, returnType, parent, funName, __VA_ARGS__)

#define _Cbj_BindFun(cbjType, returnType, parent, funName, args) \
    _Cbj_BindFun_(cbjType, returnType, parent, funName, _Cbj_Utils_stripParentheses(args))

#endif // _CBJ_BINDFUN_H
