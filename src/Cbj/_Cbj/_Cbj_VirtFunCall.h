#ifndef _CBJ_VIRTFUNCALL_H
#define _CBJ_VIRTFUNCALL_H
#include "_Cbj_Utils.h"

#define _Cbj_VirtFunCall_0(cbjType, funName, ...) \
    return ((cbjType##Class *) Cbject_class((Cbject *) me))->vf.funName(me)

#define _Cbj_VirtFunCall__(cbjType, funName, ...) \
    return ((cbjType##Class *) Cbject_class((Cbject *) me))->vf.funName(me, __VA_ARGS__)

#define _Cbj_VirtFunCall_case(cbjType, funName, case, ...) \
    _Cbj_VirtFunCall_##case (cbjType, funName, __VA_ARGS__)

#define _Cbj_VirtFunCall(cbjType, funName, ...) \
    _Cbj_VirtFunCall_case(cbjType, funName, __VA_ARGS__)

#endif // _CBJ_VIRTFUNCALL_H
