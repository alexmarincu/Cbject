#ifndef CBJECT_VIRTFUN_H
#define CBJECT_VIRTFUN_H
#include "Cbject_VirtFunImpl.h"

#define Cbject_VirtFun(cbjType, returnType, funName, args, params) \
    Cbject_VirtFunImpl(cbjType, returnType, funName, args, params)

#endif // CBJECT_VIRTFUN_H
