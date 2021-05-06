#ifndef _CBJECTVIRTUALFUNPTR_H
#define _CBJECTVIRTUALFUNPTR_H

#define _CbjectVirtualFunPtr_0(cbjectTypeName, returnType, funName, ...) \
    returnType (*funName)(cbjectTypeName * const me)

#define _CbjectVirtualFunPtr__(cbjectTypeName, returnType, funName, ...) \
    returnType (*funName)(cbjectTypeName * const me, __VA_ARGS__)

#define _CbjectVirtualFunPtr_case(cbjectTypeName, returnType, funName, case, ...) \
    _CbjectVirtualFunPtr_##case (cbjectTypeName, returnType, funName, __VA_ARGS__)

#define _CbjectVirtualFunPtr_(cbjectTypeName, type, funName, ...) \
    _CbjectVirtualFunPtr_case(cbjectTypeName, type, funName, __VA_ARGS__)

#define _CbjectVirtualFunPtr(returnType, funName, args) \
    _CbjectVirtualFunPtr_(CbjectType, returnType, funName, _CbjectUtilities_stripParentheses(args))

#endif // _CBJECTVIRTUALFUNPTR_H
