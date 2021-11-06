#ifndef CBJECT_VIRTFUNCALL_H
#define CBJECT_VIRTFUNCALL_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunCall_case(className, funName, ...) \
    typedef struct ObjectT                               \
    {                                                    \
        Cbject_Settings_maxAlign align;                  \
        ObjectType * type;                               \
    } ObjectT;                                           \
                                                         \
    return ((className##Type *)((ObjectT *)me)->type)->virtFuns.funName(me)

#define Cbject_VirtFunCall_caseParams(className, funName, ...) \
    typedef struct ObjectT                                     \
    {                                                          \
        Cbject_Settings_maxAlign align;                        \
        ObjectType * type;                                     \
    } ObjectT;                                                 \
                                                               \
    return ((className##Type *)((ObjectT *)me)->type)->virtFuns.funName(me, __VA_ARGS__)

#define Cbject_VirtFunCall_switch(className, funName, case, ...) \
    Cbject_VirtFunCall_case##case (className, funName, __VA_ARGS__)

#define Cbject_VirtFunCall_x(className, funName, ...) \
    Cbject_VirtFunCall_switch(className, funName, __VA_ARGS__)

#define Cbject_VirtFunCall(className, funName, funCallParams) \
    Cbject_VirtFunCall_x(className, funName, Cbject_Utils_unpack(funCallParams))

#endif // CBJECT_VIRTFUNCALL_H
