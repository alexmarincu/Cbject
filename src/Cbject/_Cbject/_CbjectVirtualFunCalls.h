#ifndef _CBJECTVIRTUALFUNCALLS_H
#define _CBJECTVIRTUALFUNCALLS_H
#include "_CbjectUtilities.h"

#define _CbjectVirtualFunCalls_stripParenthesesAndApplyVirtualFunCall(virtualFunPrototype) \
    VirtualFun virtualFunPrototype;

#define _CbjectVirtualFunCalls_0(...)

#define _CbjectVirtualFunCalls__(...) \
    _CbjectUtilities_forEach(_CbjectVirtualFunCalls_stripParenthesesAndApplyVirtualFunCall, __VA_ARGS__)

#define _CbjectVirtualFunCalls_(case, ...) \
    _CbjectVirtualFunCalls_##case (__VA_ARGS__)

#define _CbjectVirtualFunCalls(...) \
    _CbjectVirtualFunCalls_(__VA_ARGS__)

#endif // _CBJECTVIRTUALFUNCALLS_H
