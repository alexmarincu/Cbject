#ifndef CBJECTSUPERFUNCTION_H
#define CBJECTSUPERFUNCTION_H
#include "CbjectSuperFunctionPrototype.h"

#define CbjectSuperFunction(klassName, returnType, functionName, ...) \
    CbjectSuperFunctionPrototype(klassName, returnType, functionName, __VA_ARGS__)

#endif // CBJECTSUPERFUNCTION_H
