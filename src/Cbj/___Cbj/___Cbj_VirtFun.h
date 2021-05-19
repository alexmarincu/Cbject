#ifndef ___CBJ_VIRTFUN_H
#define ___CBJ_VIRTFUN_H
#include "___Cbj_VirtFunImpl.h"

#define ___Cbj_VirtFun(cbjType, returnType, funName, args, params) \
    ___Cbj_VirtFunImpl(cbjType, returnType, funName, args, params)

#endif // ___CBJ_VIRTFUN_H
