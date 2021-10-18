#ifndef ___CBJ_VIRTFUNCALL_H
#define ___CBJ_VIRTFUNCALL_H
#include "___Cbj_Utils.h"

#define ___Cbj_VirtFunCall_0(cbjType, funName, ...) \
    typedef struct ___Cbject                        \
    {                                               \
        Cbj_Settings_maxAlign ___align;             \
        CbjectType * type;                          \
        CbjectProps props;                          \
    } ___Cbject;                                    \
                                                    \
    return ((cbjType##Type *) ((___Cbject *) me)->type)->virtFuns.funName(me)

#define ___Cbj_VirtFunCall_(cbjType, funName, ...) \
    typedef struct ___Cbject                        \
    {                                               \
        Cbj_Settings_maxAlign ___align;             \
        CbjectType * type;                          \
        CbjectProps props;                          \
    } ___Cbject;                                    \
                                                    \
    return ((cbjType##Type *) ((___Cbject *) me)->type)->virtFuns.funName(me, __VA_ARGS__)

#define ___Cbj_VirtFunCall_case(cbjType, funName, case, ...) \
    ___Cbj_VirtFunCall_##case (cbjType, funName, __VA_ARGS__)

#define ___Cbj_VirtFunCall(cbjType, funName, ...) \
    ___Cbj_VirtFunCall_case(cbjType, funName, __VA_ARGS__)

#endif // ___CBJ_VIRTFUNCALL_H
