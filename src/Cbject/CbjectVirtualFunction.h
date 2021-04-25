#ifndef CBJECTVIRTUALFUNCTION_H
#define CBJECTVIRTUALFUNCTION_H
#include "CbjectVirtualFunctionImpl.h"

#define CbjectVirtualFunction(klassName, returnType, functionName, arguments, params) \
    CbjectVirtualFunctionImpl(klassName, returnType, functionName, arguments, params)

#endif // CBJECTVIRTUALFUNCTION_H
