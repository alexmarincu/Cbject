#ifndef _CBJECTSUPERFUNCTION_H
#define _CBJECTSUPERFUNCTION_H
#include "_CbjectSuperFunctionPrototype.h"

#define _CbjectSuperFunction(klassName, returnType, functionName, ...) \
    _CbjectSuperFunctionPrototype(klassName, returnType, functionName, __VA_ARGS__)

#endif // _CBJECTSUPERFUNCTION_H
