#ifndef CBJECT_VIRTFUN_H
#define CBJECT_VIRTFUN_H
#include "Cbject_VirtFunImpl.h"

#define Cbject_VirtFun(typeName, returnType, funName, params, callParams) \
    Cbject_VirtFunImpl(typeName, returnType, funName, params, callParams)

#endif // CBJECT_VIRTFUN_H
