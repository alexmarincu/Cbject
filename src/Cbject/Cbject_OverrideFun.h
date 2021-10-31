#ifndef CBJECT_OVERRIDEFUN_H
#define CBJECT_OVERRIDEFUN_H
#include "Cbject_OverrideFunPrototype.h"

#define Cbject_OverrideFun(typeName, returnType, funName, ...) \
    Cbject_OverrideFunPrototype(typeName, returnType, funName, __VA_ARGS__)

#endif // CBJECT_OVERRIDEFUN_H
