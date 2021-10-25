#ifndef CBJECT_SUPERFUN_H
#define CBJECT_SUPERFUN_H
#include "Cbject_SuperFunPrototype.h"

#define Cbject_SuperFun(typeName, returnType, funName, ...) \
    Cbject_SuperFunPrototype(typeName, returnType, funName, __VA_ARGS__)

#endif // CBJECT_SUPERFUN_H
