#ifndef CBJECT_FUN_H
#define CBJECT_FUN_H
#include "Cbject_FunPrototype.h"

#define Cbject_Fun(typeName, returnType, funName, ...) \
    Cbject_FunPrototype(typeName, returnType, funName, __VA_ARGS__)

#endif // CBJECT_FUN_H
