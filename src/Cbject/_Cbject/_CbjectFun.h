#ifndef _CBJECTFUNCTION_H
#define _CBJECTFUNCTION_H
#include "_CbjectFunPrototype.h"

#define _CbjectFun(cbjectTypeName, returnType, funName, ...) \
    _CbjectFunPrototype(cbjectTypeName, returnType, funName, __VA_ARGS__)

#endif // _CBJECTFUNCTION_H
