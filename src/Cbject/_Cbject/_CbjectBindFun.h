#ifndef _CBJECTBINDFUN_H
#define _CBJECTBINDFUN_H

#define _CbjectBindFun_0(cbjectTypeName, type, parentName, funName, ...) \
    ((parentName##Class *) &k)->vf.funName = (type(*)(parentName * const me)) s_##cbjectTypeName##_##funName

#define _CbjectBindFun__(cbjectTypeName, type, parentName, funName, ...) \
    ((parentName##Class *) &k)->vf.funName = (type(*)(parentName * const me, __VA_ARGS__)) s_##cbjectTypeName##_##funName

#define _CbjectBindFun_case(cbjectTypeName, type, parentName, funName, case, ...) \
    _CbjectBindFun_##case (cbjectTypeName, type, parentName, funName, __VA_ARGS__)

#define _CbjectBindFun_(cbjectTypeName, type, parentName, funName, ...) \
    _CbjectBindFun_case(cbjectTypeName, type, parentName, funName, __VA_ARGS__)

#define _CbjectBindFun(cbjectTypeName, type, parentName, funName, args) \
    _CbjectBindFun_(cbjectTypeName, type, parentName, funName, _CbjectUtilities_stripParentheses(args))

#endif // _CBJECTBINDFUN_H
