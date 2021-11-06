#ifndef CBJECT_VIRTFUN_H
#define CBJECT_VIRTFUN_H
#include "Cbject_VirtFunImpl.h"

#define Cbject_VirtFun(className, funReturnType, funName, funParams, funCallParams) \
    Cbject_VirtFunImpl(className, funReturnType, funName, funParams, funCallParams)

#endif // CBJECT_VIRTFUN_H
