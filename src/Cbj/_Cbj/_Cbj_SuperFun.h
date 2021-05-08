#ifndef _CBJ_SUPERFUN_H
#define _CBJ_SUPERFUN_H
#include "_Cbj_SuperFunPrototype.h"

#define _Cbj_SuperFun(cbjType, returnType, funName, ...) \
    _Cbj_SuperFunPrototype(cbjType, returnType, funName, __VA_ARGS__)

#endif // _CBJ_SUPERFUN_H
