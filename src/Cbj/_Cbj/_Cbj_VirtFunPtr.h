#ifndef _CBJ_VIRTFUNPTR_H
#define _CBJ_VIRTFUNPTR_H

#define _Cbj_VirtFunPtr_0(typeName, returnType, funName, ...) \
    returnType (*funName)(typeName * const me)

#define _Cbj_VirtFunPtr__(typeName, returnType, funName, ...) \
    returnType (*funName)(typeName * const me, __VA_ARGS__)

#define _Cbj_VirtFunPtr_case(typeName, returnType, funName, case, ...) \
    _Cbj_VirtFunPtr_##case (typeName, returnType, funName, __VA_ARGS__)

#define _Cbj_VirtFunPtr_(typeName, type, funName, ...) \
    _Cbj_VirtFunPtr_case(typeName, type, funName, __VA_ARGS__)

#define _Cbj_VirtFunPtr(returnType, funName, args) \
    _Cbj_VirtFunPtr_(Cbj_Type, returnType, funName, _Cbj_Utils_stripParentheses(args))

#endif // _CBJ_VIRTFUNPTR_H
