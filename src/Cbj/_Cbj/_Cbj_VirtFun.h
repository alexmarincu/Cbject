#ifndef _CBJ_VIRTFUN_H
#define _CBJ_VIRTFUN_H
#include "_Cbj_VirtFunImpl.h"

#define _Cbj_VirtFun(cbjType, returnType, funName, args, params) \
    _Cbj_VirtFunImpl(cbjType, returnType, funName, args, params)

#endif // _CBJ_VIRTFUN_H
