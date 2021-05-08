#ifndef _CBJ_OVERRIDEFUN_H
#define _CBJ_OVERRIDEFUN_H
#include "_Cbj_OverrideFunPrototype.h"

#define _Cbj_OverrideFun(typeName, returnType, funName, ...) \
    _Cbj_OverrideFunPrototype(typeName, returnType, funName, __VA_ARGS__)

#endif // _CBJ_OVERRIDEFUN_H
