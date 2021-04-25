#ifndef CBJECTVIRTUALFUNCTIONIMPL_H
#define CBJECTVIRTUALFUNCTIONIMPL_H
#include "CbjectVirtualFunctionCall.h"

#define CbjectVirtualFunctionImpl(klassName, returnType, functionName, arguments, params) \
    Function(returnType, functionName, arguments) { CbjectVirtualFunctionCall(klassName, functionName, CbjectUtilities_stripParentheses(params)); }

#endif // CBJECTVIRTUALFUNCTIONIMPL_H