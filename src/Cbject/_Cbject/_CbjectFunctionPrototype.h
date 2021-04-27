#ifndef _CBJECTFUNCTIONPROTOTYPE_H
#define _CBJECTFUNCTIONPROTOTYPE_H

#define _CbjectFunctionPrototype0(klassName, returnType, functionName, ...) \
    returnType klassName##_##functionName(klassName * const me)

#define _CbjectFunctionPrototype_(klassName, returnType, functionName, ...) \
    returnType klassName##_##functionName(klassName * const me, __VA_ARGS__)

#define _CbjectFunctionPrototype(klassName, returnType, functionName, case, ...) \
    _CbjectFunctionPrototype##case (klassName, returnType, functionName, __VA_ARGS__)

#endif // _CBJECTFUNCTIONPROTOTYPE_H
