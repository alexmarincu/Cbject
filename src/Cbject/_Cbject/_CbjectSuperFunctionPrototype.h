#ifndef _CBJECTSUPERFUNCTIONPROTOTYPE_H
#define _CBJECTSUPERFUNCTIONPROTOTYPE_H

#define _CbjectSuperFunctionPrototype0(klassName, returnType, functionName, ...) \
    returnType s##klassName##_##functionName(klassName * const me)

#define _CbjectSuperFunctionPrototype_(klassName, returnType, functionName, ...) \
    returnType s##klassName##_##functionName(klassName * const me, __VA_ARGS__)

#define _CbjectSuperFunctionPrototype(klassName, returnType, functionName, case, ...) \
    _CbjectSuperFunctionPrototype##case (klassName, returnType, functionName, __VA_ARGS__)

#endif // _CBJECTSUPERFUNCTIONPROTOTYPE_H
