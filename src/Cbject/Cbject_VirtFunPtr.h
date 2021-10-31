#ifndef CBJECT_VIRTFUNPTR_H
#define CBJECT_VIRTFUNPTR_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunPtr_void(typeName, returnType, funName, ...) \
    returnType (*funName)(typeName * const me)

#define Cbject_VirtFunPtr_(typeName, returnType, funName, ...) \
    returnType (*funName)(typeName * const me, __VA_ARGS__)

#define Cbject_VirtFunPtr_case(typeName, returnType, funName, case, ...) \
    Cbject_VirtFunPtr_##case (typeName, returnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr__(typeName, returnType, funName, ...) \
    Cbject_VirtFunPtr_case(typeName, returnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr(returnType, funName, params) \
    Cbject_VirtFunPtr__(Type, returnType, funName, Cbject_Utils_stripParentheses(params))

#endif // CBJECT_VIRTFUNPTR_H
