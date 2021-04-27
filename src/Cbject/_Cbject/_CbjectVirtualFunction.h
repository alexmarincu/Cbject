#ifndef _CBJECTVIRTUALFUNCTION_H
#define _CBJECTVIRTUALFUNCTION_H
#include "_CbjectVirtualFunctionImpl.h"

#define _CbjectVirtualFunction(klassName, returnType, functionName, arguments, params) \
    _CbjectVirtualFunctionImpl(klassName, returnType, functionName, arguments, params)

#endif // _CBJECTVIRTUALFUNCTION_H
