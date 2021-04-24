#ifndef CBJECTFUNCTION_H
#define CBJECTFUNCTION_H
#include "CbjectFunctionPrototype.h"

#define CbjectFunction(klassName, returnType, functionName, ...) \
    CbjectFunctionPrototype(klassName, returnType, functionName, __VA_ARGS__)

#endif // CBJECTFUNCTION_H
