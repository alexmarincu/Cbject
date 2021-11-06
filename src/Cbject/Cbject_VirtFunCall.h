#ifndef CBJECT_VIRTFUNCALL_H
#define CBJECT_VIRTFUNCALL_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunCall_case_(typeName, funName, ...) \
    typedef struct ObjectT                               \
    {                                                    \
        Cbject_Settings_maxAlign align;                  \
        ObjectType * type;                               \
    } ObjectT;                                           \
                                                         \
    return ((typeName##Type *)((ObjectT *)me)->type)->virtFuns.funName(me)

#define Cbject_VirtFunCall_case_params(typeName, funName, ...) \
    typedef struct ObjectT                                     \
    {                                                          \
        Cbject_Settings_maxAlign align;                        \
        ObjectType * type;                                     \
    } ObjectT;                                                 \
                                                               \
    return ((typeName##Type *)((ObjectT *)me)->type)->virtFuns.funName(me, __VA_ARGS__)

#define Cbject_VirtFunCall_switch(typeName, funName, case, ...) \
    Cbject_VirtFunCall_case_##case (typeName, funName, __VA_ARGS__)

#define Cbject_VirtFunCall_x1(typeName, funName, ...) \
    Cbject_VirtFunCall_switch(typeName, funName, __VA_ARGS__)

#define Cbject_VirtFunCall(typeName, funName, funCallParams) \
    Cbject_VirtFunCall_x1(typeName, funName, Cbject_Utils_unpack(funCallParams))

#endif // CBJECT_VIRTFUNCALL_H
