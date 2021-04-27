#ifndef _CBJECTVIRTUALFUNCTIONIMPL_H
#define _CBJECTVIRTUALFUNCTIONIMPL_H
#include "_CbjectVirtualFunctionCall.h"

#define _CbjectVirtualFunctionImpl(klassName, returnType, functionName, arguments, params) \
    Function(returnType, functionName, arguments) { _CbjectVirtualFunctionCall(klassName, functionName, _CbjectUtilities_stripParentheses(params)); }

#endif // _CBJECTVIRTUALFUNCTIONIMPL_H
