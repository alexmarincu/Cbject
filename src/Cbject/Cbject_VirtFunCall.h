#ifndef CBJECT_VIRTFUNCALL_H
#define CBJECT_VIRTFUNCALL_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunCall_case(typeName, funName, ...) \
    typedef struct ObjectT                              \
    {                                                   \
        Cbject_Settings_maxAlign align;                 \
        ObjectType * type;                              \
    } ObjectT;                                          \
                                                        \
    return ((typeName##Type *)((ObjectT *)me)->type)->virtFuns.funName(me)

#define Cbject_VirtFunCall_caseParams(typeName, funName, ...) \
    typedef struct ObjectT                                    \
    {                                                         \
        Cbject_Settings_maxAlign align;                       \
        ObjectType * type;                                    \
    } ObjectT;                                                \
                                                              \
    return ((typeName##Type *)((ObjectT *)me)->type)->virtFuns.funName(me, __VA_ARGS__)

#define Cbject_VirtFunCall_switch(typeName, funName, case, ...) \
    Cbject_VirtFunCall_case##case (typeName, funName, __VA_ARGS__)

#define Cbject_VirtFunCall_x(typeName, funName, ...) \
    Cbject_VirtFunCall_switch(typeName, funName, __VA_ARGS__)

#define Cbject_VirtFunCall(typeName, funName, funCallParams) \
    Cbject_VirtFunCall_x(typeName, funName, Cbject_Utils_unpack(funCallParams))

#endif // CBJECT_VIRTFUNCALL_H
