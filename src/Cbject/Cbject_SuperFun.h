#ifndef CBJECT_SUPERFUN_H
#define CBJECT_SUPERFUN_H
#include "Cbject_SuperFunPrototype.h"

#define Cbject_SuperFun(cbjType, returnType, funName, ...) \
    Cbject_SuperFunPrototype(cbjType, returnType, funName, __VA_ARGS__)

#endif // CBJECT_SUPERFUN_H
