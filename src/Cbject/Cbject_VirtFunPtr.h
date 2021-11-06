#ifndef CBJECT_VIRTFUNPTR_H
#define CBJECT_VIRTFUNPTR_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunPtr_case(typeName, funReturnType, funName, ...) \
    funReturnType (*funName)(typeName * const me)

#define Cbject_VirtFunPtr_caseParams(typeName, funReturnType, funName, ...) \
    funReturnType (*funName)(typeName * const me, __VA_ARGS__)

#define Cbject_VirtFunPtr_switch(typeName, funReturnType, funName, case, ...) \
    Cbject_VirtFunPtr_case##case (typeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr_x(typeName, funReturnType, funName, ...) \
    Cbject_VirtFunPtr_switch(typeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr(funReturnType, funName, funParams) \
    Cbject_VirtFunPtr_x(Type, funReturnType, funName, Cbject_Utils_unpack(funParams))

#endif // CBJECT_VIRTFUNPTR_H
