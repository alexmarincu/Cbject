#ifndef CBJECT_VIRTFUNCALL_H
#define CBJECT_VIRTFUNCALL_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunCall_0(cbjType, funName, ...) \
    typedef struct CbjectContainer                  \
    {                                               \
        Cbject_Settings_maxAlign a;                 \
        CbjectType * type;                          \
        CbjectProps props;                          \
    } CbjectContainer;                              \
                                                    \
    return ((cbjType##Type *) ((CbjectContainer *) me)->type)->virtFuns.funName(me)

#define Cbject_VirtFunCall_(cbjType, funName, ...) \
    typedef struct CbjectContainer                 \
    {                                              \
        Cbject_Settings_maxAlign a;                \
        CbjectType * type;                         \
        CbjectProps props;                         \
    } CbjectContainer;                             \
                                                   \
    return ((cbjType##Type *) ((CbjectContainer *) me)->type)->virtFuns.funName(me, __VA_ARGS__)

#define Cbject_VirtFunCall_case(cbjType, funName, case, ...) \
    Cbject_VirtFunCall_##case (cbjType, funName, __VA_ARGS__)

#define Cbject_VirtFunCall(cbjType, funName, ...) \
    Cbject_VirtFunCall_case(cbjType, funName, __VA_ARGS__)

#endif // CBJECT_VIRTFUNCALL_H
