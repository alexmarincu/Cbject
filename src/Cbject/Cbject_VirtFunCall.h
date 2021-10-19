#ifndef CBJECT_VIRTFUNCALL_H
#define CBJECT_VIRTFUNCALL_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunCall_0(cbjType, funName, ...) \
    typedef struct ___Cbject                        \
    {                                               \
        Cbject_Settings_maxAlign ___align;          \
        CbjectType * type;                          \
        CbjectProps props;                          \
    } ___Cbject;                                    \
                                                    \
    return ((cbjType##Type *) ((___Cbject *) me)->type)->virtFuns.funName(me)

#define Cbject_VirtFunCall_(cbjType, funName, ...) \
    typedef struct ___Cbject                       \
    {                                              \
        Cbject_Settings_maxAlign ___align;         \
        CbjectType * type;                         \
        CbjectProps props;                         \
    } ___Cbject;                                   \
                                                   \
    return ((cbjType##Type *) ((___Cbject *) me)->type)->virtFuns.funName(me, __VA_ARGS__)

#define Cbject_VirtFunCall_case(cbjType, funName, case, ...) \
    Cbject_VirtFunCall_##case (cbjType, funName, __VA_ARGS__)

#define Cbject_VirtFunCall(cbjType, funName, ...) \
    Cbject_VirtFunCall_case(cbjType, funName, __VA_ARGS__)

#endif // CBJECT_VIRTFUNCALL_H
