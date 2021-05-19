#ifndef ___CBJ_FUN_H
#define ___CBJ_FUN_H
#include "___Cbj_FunPrototype.h"

#define ___Cbj_Fun(cbjType, returnType, funName, ...) \
    ___Cbj_FunPrototype(cbjType, returnType, funName, __VA_ARGS__)

#endif // ___CBJ_FUN_H
