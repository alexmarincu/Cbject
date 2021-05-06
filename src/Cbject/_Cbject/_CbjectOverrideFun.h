#ifndef _CBJECTOVERRIDEFUN_H
#define _CBJECTOVERRIDEFUN_H
#include "_CbjectOverrideFunPrototype.h"

#define _CbjectOverrideFun(cbjectTypeName, returnType, funName, ...) \
    _CbjectOverrideFunPrototype(cbjectTypeName, returnType, funName, __VA_ARGS__)

#endif // _CBJECTOVERRIDEFUN_H
