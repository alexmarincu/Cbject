#ifndef _CBJ_BINDFUN_H
#define _CBJ_BINDFUN_H

#define _Cbj_BindFun_0(typeName, returnType, Cbj_ParentName, funName, ...) \
    ((Cbj_ParentName##Class *) &c)->vf.funName = (returnType(*)(Cbj_ParentName * const me)) s_##typeName##_##funName

#define _Cbj_BindFun__(typeName, returnType, Cbj_ParentName, funName, ...) \
    ((Cbj_ParentName##Class *) &c)->vf.funName = (returnType(*)(Cbj_ParentName * const me, __VA_ARGS__)) s_##typeName##_##funName

#define _Cbj_BindFun_case(typeName, returnType, Cbj_ParentName, funName, case, ...) \
    _Cbj_BindFun_##case (typeName, returnType, Cbj_ParentName, funName, __VA_ARGS__)

#define _Cbj_BindFun_(typeName, returnType, Cbj_ParentName, funName, ...) \
    _Cbj_BindFun_case(typeName, returnType, Cbj_ParentName, funName, __VA_ARGS__)

#define _Cbj_BindFun(typeName, returnType, Cbj_ParentName, funName, args) \
    _Cbj_BindFun_(typeName, returnType, Cbj_ParentName, funName, _Cbj_Utils_stripParentheses(args))

#endif // _CBJ_BINDFUN_H
