#ifndef CBJECT_VIRTFUNPTR_H
#define CBJECT_VIRTFUNPTR_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunPtr_0(cbjType, returnType, funName, ...) \
    returnType (*funName)(cbjType * const me)

#define Cbject_VirtFunPtr_(cbjType, returnType, funName, ...) \
    returnType (*funName)(cbjType * const me, __VA_ARGS__)

#define Cbject_VirtFunPtr_case(cbjType, returnType, funName, case, ...) \
    Cbject_VirtFunPtr_##case (cbjType, returnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr__(cbjType, returnType, funName, ...) \
    Cbject_VirtFunPtr_case(cbjType, returnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr(returnType, funName, args) \
    Cbject_VirtFunPtr__(Type, returnType, funName, Cbject_Utils_stripParentheses(args))

#endif // CBJECT_VIRTFUNPTR_H
