#ifndef _CBJECTVIRTUALFUNCTIONCALL_H
#define _CBJECTVIRTUALFUNCTIONCALL_H
#include "_CbjectUtilities.h"

#define _CbjectVirtualFunctionCall_0(klassName, functionName, ...) \
    return ((klassName##Klass *) Cbject_klass((Cbject *) me))->vf.functionName(me)

#define _CbjectVirtualFunctionCall__(klassName, functionName, ...) \
    return ((klassName##Klass *) Cbject_klass((Cbject *) me))->vf.functionName(me, __VA_ARGS__)

#define _CbjectVirtualFunctionCall_case(klassName, functionName, case, ...) \
    _CbjectVirtualFunctionCall_##case (klassName, functionName, __VA_ARGS__)

#define _CbjectVirtualFunctionCall(klassName, functionName, ...) \
    _CbjectVirtualFunctionCall_case(klassName, functionName, __VA_ARGS__)

#endif // _CBJECTVIRTUALFUNCTIONCALL_H
