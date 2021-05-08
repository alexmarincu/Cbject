#ifndef _CBJ_VIRTFUNCALL_H
#define _CBJ_VIRTFUNCALL_H
#include "_Cbj_Utils.h"

#define _Cbj_VirtFunCall_0(typeName, funName, ...) \
    return ((typeName##Class *) Cbj_Base_class((Cbj_Base *) me))->vf.funName(me)

#define _Cbj_VirtFunCall__(typeName, funName, ...) \
    return ((typeName##Class *) Cbj_Base_class((Cbj_Base *) me))->vf.funName(me, __VA_ARGS__)

#define _Cbj_VirtFunCall_case(typeName, funName, case, ...) \
    _Cbj_VirtFunCall_##case (typeName, funName, __VA_ARGS__)

#define _Cbj_VirtFunCall(typeName, funName, ...) \
    _Cbj_VirtFunCall_case(typeName, funName, __VA_ARGS__)

#endif // _CBJ_VIRTFUNCALL_H
