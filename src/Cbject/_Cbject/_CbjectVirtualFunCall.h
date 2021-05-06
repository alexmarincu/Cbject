#ifndef _CBJECTVIRTUALFUNCTIONCALL_H
#define _CBJECTVIRTUALFUNCTIONCALL_H
#include "_CbjectUtilities.h"

#define _CbjectVirtualFunCall_0(cbjectTypeName, funName, ...) \
    return ((cbjectTypeName##Class *) Cbject_CbjectType((Cbject *) me))->vf.funName(me)

#define _CbjectVirtualFunCall__(cbjectTypeName, funName, ...) \
    return ((cbjectTypeName##Class *) Cbject_CbjectType((Cbject *) me))->vf.funName(me, __VA_ARGS__)

#define _CbjectVirtualFunCall_case(cbjectTypeName, funName, case, ...) \
    _CbjectVirtualFunCall_##case (cbjectTypeName, funName, __VA_ARGS__)

#define _CbjectVirtualFunCall(cbjectTypeName, funName, ...) \
    _CbjectVirtualFunCall_case(cbjectTypeName, funName, __VA_ARGS__)

#endif // _CBJECTVIRTUALFUNCTIONCALL_H
