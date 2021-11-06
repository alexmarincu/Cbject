#ifndef CBJECT_VIRTFUNPTR_H
#define CBJECT_VIRTFUNPTR_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunPtr_case_(typeName, funReturnType, funName, ...) \
    funReturnType (*funName)(typeName * const me)

#define Cbject_VirtFunPtr_case_Params(typeName, funReturnType, funName, ...) \
    funReturnType (*funName)(typeName * const me, __VA_ARGS__)

#define Cbject_VirtFunPtr_switch(typeName, funReturnType, funName, case, ...) \
    Cbject_VirtFunPtr_case_##case (typeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr_x1(typeName, funReturnType, funName, ...) \
    Cbject_VirtFunPtr_switch(typeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr(funReturnType, funName, funParams) \
    Cbject_VirtFunPtr_x1(Type, funReturnType, funName, Cbject_Utils_unpack(funParams))

#endif // CBJECT_VIRTFUNPTR_H
