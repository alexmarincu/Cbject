#ifndef _CBJ_VIRTFUNCALL_H
#define _CBJ_VIRTFUNCALL_H
#include "_Cbj_Utils.h"

#define _Cbj_VirtFunCall_0(cbjType, funName, ...) \
    typedef struct _Cbject                        \
    {                                             \
        Cbj_Settings_maxAlign xalign;                  \
        CbjectType * type;                           \
        CbjectProps props;                            \
    } _Cbject;                                    \
                                                  \
    return ((cbjType##Type *) ((_Cbject *) me)->type)->virtFuns.funName(me)

#define _Cbj_VirtFunCall__(cbjType, funName, ...) \
    typedef struct _Cbject                        \
    {                                             \
        Cbj_Settings_maxAlign xalign;                  \
        CbjectType * type;                           \
        CbjectProps props;                            \
    } _Cbject;                                    \
                                                  \
    return ((cbjType##Type *) ((_Cbject *) me)->type)->virtFuns.funName(me, __VA_ARGS__)

#define _Cbj_VirtFunCall_case(cbjType, funName, case, ...) \
    _Cbj_VirtFunCall_##case (cbjType, funName, __VA_ARGS__)

#define _Cbj_VirtFunCall(cbjType, funName, ...) \
    _Cbj_VirtFunCall_case(cbjType, funName, __VA_ARGS__)

#endif // _CBJ_VIRTFUNCALL_H
