#ifndef CBJECT_VIRTFUN_H
#define CBJECT_VIRTFUN_H
#include "Cbject_Utils.h"
#include "Cbject_VirtFun.h"

#define Cbject_VirtFun_Call_case(className, funName, ...) \
    typedef struct ObjectT                                \
    {                                                     \
        Cbject_Settings_maxAlign align;                   \
        ObjectType * type;                                \
    } ObjectT;                                            \
                                                          \
    return ((className##Type *)((ObjectT *)me)->type)->virtFuns.funName(me)

#define Cbject_VirtFun_Call_caseParams(className, funName, ...) \
    typedef struct ObjectT                                      \
    {                                                           \
        Cbject_Settings_maxAlign align;                         \
        ObjectType * type;                                      \
    } ObjectT;                                                  \
                                                                \
    return ((className##Type *)((ObjectT *)me)->type)->virtFuns.funName(me, __VA_ARGS__)

#define Cbject_VirtFun_Call_x1(className, funName, case, ...) \
    Cbject_VirtFun_Call_case##case (className, funName, __VA_ARGS__)

#define Cbject_VirtFun_Call_x0(className, funName, ...) \
    Cbject_VirtFun_Call_x1(className, funName, __VA_ARGS__)

#define Cbject_VirtFun_Call(className, funName, funCallParams) \
    Cbject_VirtFun_Call_x0(className, funName, Cbject_Utils_unpack(funCallParams))

//

#define Cbject_VirtFun_Impl(className, funReturnType, funName, funParams, funCallParams) \
    Fun(funReturnType, funName, funParams) { Cbject_VirtFun_Call(className, funName, funCallParams); }

#endif // CBJECT_VIRTFUN_H
