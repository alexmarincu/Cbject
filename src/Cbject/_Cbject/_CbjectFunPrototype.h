#ifndef _CBJECTFUNCTIONPROTOTYPE_H
#define _CBJECTFUNCTIONPROTOTYPE_H

#define _CbjectFunPrototype_0(cbjectTypeName, returnType, funName, ...) \
    returnType cbjectTypeName##_##funName(cbjectTypeName * const me)

#define _CbjectFunPrototype__(cbjectTypeName, returnType, funName, ...) \
    returnType cbjectTypeName##_##funName(cbjectTypeName * const me, __VA_ARGS__)

#define _CbjectFunPrototype(cbjectTypeName, returnType, funName, case, ...) \
    _CbjectFunPrototype_##case (cbjectTypeName, returnType, funName, __VA_ARGS__)

#endif // _CBJECTFUNCTIONPROTOTYPE_H
