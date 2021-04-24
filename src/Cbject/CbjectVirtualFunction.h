#ifndef CBJECTVIRTUALFUNCTION_H
#define CBJECTVIRTUALFUNCTION_H
#include "CbjectVirtualFunctionImpl.h"

#define CbjectVirtualFunction(klassName, returnType, functionName, arguments, params) \
    CbjectVirtualFunctionImpl(klassName, returnType, functionName, arguments, CbjectUtilities_stripParentheses(params))

#endif // CBJECTVIRTUALFUNCTION_H
