#ifndef _CBJECTVIRTUALFUNCTIONIMPL_H
#define _CBJECTVIRTUALFUNCTIONIMPL_H
#include "_CbjectVirtualFunCall.h"

#define _CbjectVirtualFunImpl(cbjectTypeName, returnType, funName, args, params) \
    Fun(returnType, funName, args) { _CbjectVirtualFunCall(cbjectTypeName, funName, _CbjectUtilities_stripParentheses(params)); }

#endif // _CBJECTVIRTUALFUNCTIONIMPL_H
