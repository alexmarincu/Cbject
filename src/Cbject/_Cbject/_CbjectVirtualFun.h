#ifndef _CBJECTVIRTUALFUNCTION_H
#define _CBJECTVIRTUALFUNCTION_H
#include "_CbjectVirtualFunImpl.h"

#define _CbjectVirtualFun(cbjectTypeName, returnType, funName, args, params) \
    _CbjectVirtualFunImpl(cbjectTypeName, returnType, funName, args, params)

#endif // _CBJECTVIRTUALFUNCTION_H
