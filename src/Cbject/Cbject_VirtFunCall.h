#ifndef CBJECT_VIRTFUNCALL_H
#define CBJECT_VIRTFUNCALL_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunCall_0(typeName, funName, ...) \
    typedef struct CbjectContainer                   \
    {                                                \
        Cbject_Settings_maxAlign a;                  \
        CbjectType * t;                              \
    } CbjectContainer;                               \
                                                     \
    return ((typeName##Type *) ((CbjectContainer *) me)->t)->vf.funName(me)

#define Cbject_VirtFunCall_(typeName, funName, ...) \
    typedef struct CbjectContainer                  \
    {                                               \
        Cbject_Settings_maxAlign a;                 \
        CbjectType * t;                             \
    } CbjectContainer;                              \
                                                    \
    return ((typeName##Type *) ((CbjectContainer *) me)->t)->vf.funName(me, __VA_ARGS__)

#define Cbject_VirtFunCall_case(typeName, funName, case, ...) \
    Cbject_VirtFunCall_##case (typeName, funName, __VA_ARGS__)

#define Cbject_VirtFunCall(typeName, funName, ...) \
    Cbject_VirtFunCall_case(typeName, funName, __VA_ARGS__)

#endif // CBJECT_VIRTFUNCALL_H
