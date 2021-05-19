#ifndef ___CBJ_SUPERFUN_H
#define ___CBJ_SUPERFUN_H
#include "___Cbj_SuperFunPrototype.h"

#define ___Cbj_SuperFun(cbjType, returnType, funName, ...) \
    ___Cbj_SuperFunPrototype(cbjType, returnType, funName, __VA_ARGS__)

#endif // ___CBJ_SUPERFUN_H
