#ifndef _CBJECTOVERRIDEFUNPROTOTYPE_H
#define _CBJECTOVERRIDEFUNPROTOTYPE_H

#define _CbjectOverrideFunPrototype_0(cbjectTypeName, returnType, funName, ...) \
    returnType s_##cbjectTypeName##_##funName(cbjectTypeName * const me)

#define _CbjectOverrideFunPrototype__(cbjectTypeName, returnType, funName, ...) \
    returnType s_##cbjectTypeName##_##funName(cbjectTypeName * const me, __VA_ARGS__)

#define _CbjectOverrideFunPrototype(cbjectTypeName, returnType, funName, case, ...) \
    _CbjectOverrideFunPrototype_##case (cbjectTypeName, returnType, funName, __VA_ARGS__)

#endif // _CBJECTOVERRIDEFUNPROTOTYPE_H
