#ifndef CBJECT_VIRTFUNPTR_H
#define CBJECT_VIRTFUNPTR_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunPtr_case(className, funReturnType, funName, ...) \
    funReturnType (*funName)(className * const me)

#define Cbject_VirtFunPtr_caseParams(className, funReturnType, funName, ...) \
    funReturnType (*funName)(className * const me, __VA_ARGS__)

#define Cbject_VirtFunPtr_switch(className, funReturnType, funName, case, ...) \
    Cbject_VirtFunPtr_case##case (className, funReturnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr_x(className, funReturnType, funName, ...) \
    Cbject_VirtFunPtr_switch(className, funReturnType, funName, __VA_ARGS__)

#define Cbject_VirtFunPtr(funReturnType, funName, funParams) \
    Cbject_VirtFunPtr_x(Type, funReturnType, funName, Cbject_Utils_unpack(funParams))

#endif // CBJECT_VIRTFUNPTR_H
