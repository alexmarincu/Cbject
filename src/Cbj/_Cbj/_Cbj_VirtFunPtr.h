#ifndef _CBJ_VIRTFUNPTR_H
#define _CBJ_VIRTFUNPTR_H
#include "_Cbj_Utils.h"

#define _Cbj_VirtFunPtr_0(cbjType, returnType, funName, ...) \
    returnType (*funName)(cbjType * const me)

#define _Cbj_VirtFunPtr__(cbjType, returnType, funName, ...) \
    returnType (*funName)(cbjType * const me, __VA_ARGS__)

#define _Cbj_VirtFunPtr_case(cbjType, returnType, funName, case, ...) \
    _Cbj_VirtFunPtr_##case (cbjType, returnType, funName, __VA_ARGS__)

#define _Cbj_VirtFunPtr_(cbjType, returnType, funName, ...) \
    _Cbj_VirtFunPtr_case(cbjType, returnType, funName, __VA_ARGS__)

#define _Cbj_VirtFunPtr(returnType, funName, args) \
    _Cbj_VirtFunPtr_(Type, returnType, funName, _Cbj_Utils_stripParentheses(args))

#endif // _CBJ_VIRTFUNPTR_H
