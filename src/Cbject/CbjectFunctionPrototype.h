#ifndef CBJECTFUNCTIONPROTOTYPE_H
#define CBJECTFUNCTIONPROTOTYPE_H

#define CbjectFunctionPrototype0(klassName, returnType, functionName, ...) \
    returnType klassName##_##functionName(klassName * const me)

#define CbjectFunctionPrototype_(klassName, returnType, functionName, ...) \
    returnType klassName##_##functionName(klassName * const me, __VA_ARGS__)

#define CbjectFunctionPrototype(klassName, returnType, functionName, case, ...) \
    CbjectFunctionPrototype##case (klassName, returnType, functionName, __VA_ARGS__)

#endif // CBJECTFUNCTIONPROTOTYPE_H
