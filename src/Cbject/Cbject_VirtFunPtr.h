#ifndef CBJECT_VIRTFUNPTR_H
#define CBJECT_VIRTFUNPTR_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunPtr_case_(typeName, returnType, funName, ...) \
    returnType (*funName)(typeName * const me)

#define Cbject_VirtFunPtr_case_params(typeName, returnType, funName, ...) \
    returnType (*funName)(typeName * const me, __VA_ARGS__)

#define Cbject_VirtFunPtr_switch(typeName, returnType, funName, case, ...) \
    Cbject_VirtFunPtr_case_##case (typeName, returnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr_x1(typeName, returnType, funName, ...) \
    Cbject_VirtFunPtr_switch(typeName, returnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr(returnType, funName, params) \
    Cbject_VirtFunPtr_x1(Type, returnType, funName, Cbject_Utils_stripParentheses(params))

#endif // CBJECT_VIRTFUNPTR_H
