#ifndef CBJECTVIRTUALFUNCTIONIMPL_H
#define CBJECTVIRTUALFUNCTIONIMPL_H
#include "CbjectVirtualFunctionCall.h"

#define CbjectVirtualFunctionImpl(klassName, returnType, functionName, arguments, ...) \
    Function(returnType, functionName, arguments)                                      \
    {                                                                                  \
        CbjectVirtualFunctionCall(klassName, functionName, __VA_ARGS__);               \
    }

#endif // CBJECTVIRTUALFUNCTIONIMPL_H
