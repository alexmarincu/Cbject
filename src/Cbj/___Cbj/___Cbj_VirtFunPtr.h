#ifndef ___CBJ_VIRTFUNPTR_H
#define ___CBJ_VIRTFUNPTR_H
#include "___Cbj_Utils.h"

#define ___Cbj_VirtFunPtr_0(cbjType, returnType, funName, ...) \
    returnType (*funName)(cbjType * const me)

#define ___Cbj_VirtFunPtr__(cbjType, returnType, funName, ...) \
    returnType (*funName)(cbjType * const me, __VA_ARGS__)

#define ___Cbj_VirtFunPtr_case(cbjType, returnType, funName, case, ...) \
    ___Cbj_VirtFunPtr_##case (cbjType, returnType, funName, __VA_ARGS__)

#define ___Cbj_VirtFunPtr_(cbjType, returnType, funName, ...) \
    ___Cbj_VirtFunPtr_case(cbjType, returnType, funName, __VA_ARGS__)

#define ___Cbj_VirtFunPtr(returnType, funName, args) \
    ___Cbj_VirtFunPtr_(Type, returnType, funName, ___Cbj_Utils_stripParentheses(args))

#endif // ___CBJ_VIRTFUNPTR_H
