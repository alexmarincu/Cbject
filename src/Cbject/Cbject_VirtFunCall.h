#ifndef CBJECT_VIRTFUNCALL_H
#define CBJECT_VIRTFUNCALL_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunCall_case_(typeName, funName, ...) \
    typedef struct ObjectT                               \
    {                                                    \
        Cbject_Settings_maxAlign a;                      \
        ObjectType * t;                                  \
    } ObjectT;                                           \
                                                         \
    return ((typeName##Type *)((ObjectT *)me)->t)->vf.funName(me)

#define Cbject_VirtFunCall_case_args(typeName, funName, ...) \
    typedef struct ObjectT                                   \
    {                                                        \
        Cbject_Settings_maxAlign a;                          \
        ObjectType * t;                                      \
    } ObjectT;                                               \
                                                             \
    return ((typeName##Type *)((ObjectT *)me)->t)->vf.funName(me, __VA_ARGS__)

#define Cbject_VirtFunCall_switch(typeName, funName, case, ...) \
    Cbject_VirtFunCall_case_##case (typeName, funName, __VA_ARGS__)

#define Cbject_VirtFunCall(typeName, funName, ...) \
    Cbject_VirtFunCall_switch(typeName, funName, __VA_ARGS__)

#endif // CBJECT_VIRTFUNCALL_H
