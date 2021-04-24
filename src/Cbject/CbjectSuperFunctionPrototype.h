#ifndef CBJECTSUPERFUNCTIONPROTOTYPE_H
#define CBJECTSUPERFUNCTIONPROTOTYPE_H

#define CbjectSuperFunctionPrototype0(klassName, returnType, functionName, ...) \
    returnType super##klassName##_##functionName(klassName * const me)

#define CbjectSuperFunctionPrototype_(klassName, returnType, functionName, ...) \
    returnType super##klassName##_##functionName(klassName * const me, __VA_ARGS__)

#define CbjectSuperFunctionPrototype(klassName, returnType, functionName, case, ...) \
    CbjectSuperFunctionPrototype##case (klassName, returnType, functionName, __VA_ARGS__)

#endif // CBJECTSUPERFUNCTIONPROTOTYPE_H
