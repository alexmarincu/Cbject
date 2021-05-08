#ifndef _CBJ_FUN_H
#define _CBJ_FUN_H
#include "_Cbj_FunPrototype.h"

#define _Cbj_Fun(typeName, returnType, funName, ...) \
    _Cbj_FunPrototype(typeName, returnType, funName, __VA_ARGS__)

#endif // _CBJ_FUN_H
