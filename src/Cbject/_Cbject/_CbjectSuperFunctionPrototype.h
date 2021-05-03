#ifndef _CBJECTSUPERFUNCTIONPROTOTYPE_H
#define _CBJECTSUPERFUNCTIONPROTOTYPE_H

#define _CbjectSuperFunctionPrototype_0(klassName, returnType, functionName, ...) \
    returnType s##klassName##_##functionName(klassName * const me)

#define _CbjectSuperFunctionPrototype__(klassName, returnType, functionName, ...) \
    returnType s##klassName##_##functionName(klassName * const me, __VA_ARGS__)

#define _CbjectSuperFunctionPrototype(klassName, returnType, functionName, case, ...) \
    _CbjectSuperFunctionPrototype_##case (klassName, returnType, functionName, __VA_ARGS__)

#endif // _CBJECTSUPERFUNCTIONPROTOTYPE_H
