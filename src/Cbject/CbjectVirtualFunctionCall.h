#ifndef CBJECTVIRTUALFUNCTIONCALL_H
#define CBJECTVIRTUALFUNCTIONCALL_H
#include "CbjectUtilities.h"

#define CbjectVirtualFunctionCall0(klassName, functionName, ...) \
    return ((klassName##Klass *) Cbject_klass((Cbject *) me))->vf.functionName(me)

#define CbjectVirtualFunctionCall_(klassName, functionName, ...) \
    return ((klassName##Klass *) Cbject_klass((Cbject *) me))->vf.functionName(me, __VA_ARGS__)

#define CbjectVirtualFunctionCall_case(klassName, functionName, case, ...) \
    CbjectVirtualFunctionCall##case (klassName, functionName, __VA_ARGS__)

#define CbjectVirtualFunctionCall(klassName, functionName, ...) \
    CbjectVirtualFunctionCall_case(klassName, functionName, __VA_ARGS__)

#endif // CBJECTVIRTUALFUNCTIONCALL_H
