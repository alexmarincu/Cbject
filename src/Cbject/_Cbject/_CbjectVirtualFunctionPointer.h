#ifndef _CBJECTVIRTUALFUNCTIONPOINTER_H
#define _CBJECTVIRTUALFUNCTIONPOINTER_H

#define _CbjectVirtualFunctionPointer_0(klassName, returnType, functionName, ...) \
    returnType (*functionName)(klassName * const me)

#define _CbjectVirtualFunctionPointer__(klassName, returnType, functionName, ...) \
    returnType (*functionName)(klassName * const me, __VA_ARGS__)

#define _CbjectVirtualFunctionPointer_case(klassName, returnType, functionName, case, ...) \
    _CbjectVirtualFunctionPointer_##case (klassName, returnType, functionName, __VA_ARGS__)

#define _CbjectVirtualFunctionPointer_(klassName, type, functionName, ...) \
    _CbjectVirtualFunctionPointer_case(klassName, type, functionName, __VA_ARGS__)

#define _CbjectVirtualFunctionPointer(returnType, functionName, arguments) \
    _CbjectVirtualFunctionPointer_(klass, returnType, functionName, _CbjectUtilities_stripParentheses(arguments))

#endif // _CBJECTVIRTUALFUNCTIONPOINTER_H
