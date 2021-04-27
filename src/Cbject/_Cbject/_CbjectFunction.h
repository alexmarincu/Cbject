#ifndef _CBJECTFUNCTION_H
#define _CBJECTFUNCTION_H
#include "_CbjectFunctionPrototype.h"

#define _CbjectFunction(klassName, returnType, functionName, ...) \
    _CbjectFunctionPrototype(klassName, returnType, functionName, __VA_ARGS__)

#endif // _CBJECTFUNCTION_H
